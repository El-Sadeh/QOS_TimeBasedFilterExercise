
#include <algorithm>
#include <iostream>

#include <dds/sub/ddssub.hpp>
#include <dds/core/ddscore.hpp>
// Or simply include <dds/dds.hpp> 

#include "TimeBasedFilterExercise.hpp"

class TemperateureReaderListener : public dds::sub::NoOpDataReaderListener<Temperateure> {
  public:

    TemperateureReaderListener() : count_ (0)
    {
    }

    void on_data_available(dds::sub::DataReader<Temperateure>& reader)
    {
        // Take all samples
        dds::sub::LoanedSamples<Temperateure> samples = reader.take();

        for ( dds::sub::LoanedSamples<Temperateure>::iterator sample_it = samples.begin();
        sample_it != samples.end(); sample_it++) {

            if (sample_it->info().valid()){
                count_++;
                std::cout << sample_it->data() << std::endl; 
            }        
        }      
    }

    int count() const
    {
        return count_;
    }

  private:
    int count_;
};

void subscriber_main(int domain_id, int sample_count)
{
    // Create a DomainParticipant with default Qos
    dds::domain::DomainParticipant participant(domain_id);

    // Create a Topic -- and automatically register the type
    dds::topic::Topic<Temperateure> topic(participant, "Example Temperateure");

    // Create a DataReader with default Qos (Subscriber created in-line)
    TemperateureReaderListener listener;
    dds::sub::DataReader<Temperateure> reader(
        dds::sub::Subscriber(participant),
        topic,
        dds::core::QosProvider::Default().datareader_qos(),
        &listener,
        dds::core::status::StatusMask::data_available());

    while (listener.count() < sample_count || sample_count == 0) {

       	
        rti::util::sleep(dds::core::Duration(10));
		//GS - this flow will happend  every 10 sec. Why?
		std::cout << "Changing Time Based Filter in real time:" << std::endl;
		//Save the current qos data reder to menipulate.
		//NOTE: we could avoid that part and change everything directly. just for readability
		dds::sub::qos::DataReaderQos oldQOS = reader->qos();
		//Need to access the native struct of the time based filter: 
		oldQOS->time_based_filter->native().minimum_separation.nanosec = 500000000;
		//Now set the QOS
		reader->qos(oldQOS);

		//GS - Did you check that it actually work?

    }

    // Unset the listener to allow the reader destruction
    // (rti::core::ListenerBinder can do this automatically)
    reader.listener(NULL, dds::core::status::StatusMask::none());  
}

int main(int argc, char *argv[])
{

    int domain_id = 0;
    int sample_count = 0; // infinite loop

    if (argc >= 2) {
        domain_id = atoi(argv[1]);
    }
    if (argc >= 3) {
        sample_count = atoi(argv[2]);
    }

    // To turn on additional logging, include <rti/config/Logger.hpp> and
    // uncomment the following line:
    // rti::config::Logger::instance().verbosity(rti::config::Verbosity::STATUS_ALL);

    try {
        subscriber_main(domain_id, sample_count);
    } catch (const std::exception& ex) {
        // This will catch DDS exceptions
        std::cerr << "Exception in subscriber_main(): " << ex.what() << std::endl;
        return -1;
    }

    // RTI Connext provides a finalize_participant_factory() method
    // if you want to release memory used by the participant factory singleton.
    // Uncomment the following line to release the singleton:
    //
    // dds::domain::DomainParticipant::finalize_participant_factory();

    return 0;
}

