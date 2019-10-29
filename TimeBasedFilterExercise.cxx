

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from TimeBasedFilterExercise.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#include <iosfwd>
#include <iomanip>

#include "rti/topic/cdr/Serialization.hpp"

#include "TimeBasedFilterExercise.hpp"
#include "TimeBasedFilterExercisePlugin.hpp"

#include <rti/util/ostream_operators.hpp>

// ---- Temperateure: 

Temperateure::Temperateure() :
    m_currentTemperature_ (0)  {
}   

Temperateure::Temperateure (
    int16_t currentTemperature)
    :
        m_currentTemperature_( currentTemperature ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
Temperateure::Temperateure(Temperateure&& other_) OMG_NOEXCEPT  :m_currentTemperature_ (std::move(other_.m_currentTemperature_))
{
} 

Temperateure& Temperateure::operator=(Temperateure&&  other_) OMG_NOEXCEPT {
    Temperateure tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void Temperateure::swap(Temperateure& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_currentTemperature_, other_.m_currentTemperature_);
}  

bool Temperateure::operator == (const Temperateure& other_) const {
    if (m_currentTemperature_ != other_.m_currentTemperature_) {
        return false;
    }
    return true;
}
bool Temperateure::operator != (const Temperateure& other_) const {
    return !this->operator ==(other_);
}

// --- Getters and Setters: -------------------------------------------------
int16_t& Temperateure::currentTemperature() OMG_NOEXCEPT {
    return m_currentTemperature_;
}

const int16_t& Temperateure::currentTemperature() const OMG_NOEXCEPT {
    return m_currentTemperature_;
}

void Temperateure::currentTemperature(int16_t value) {
    m_currentTemperature_ = value;
}

std::ostream& operator << (std::ostream& o,const Temperateure& sample)
{
    rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "currentTemperature: " << sample.currentTemperature() ;
    o <<"]";
    return o;
}

// --- Type traits: -------------------------------------------------

namespace rti { 
    namespace topic {

        template<>
        struct native_type_code<Temperateure> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member Temperateure_g_tc_members[1]=
                {

                    {
                        (char *)"currentTemperature",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode Temperateure_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"Temperateure", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        Temperateure_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for Temperateure*/

                if (is_initialized) {
                    return &Temperateure_g_tc;
                }

                Temperateure_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;

                is_initialized = RTI_TRUE;

                return &Temperateure_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<Temperateure>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<Temperateure>::get())));
        }

    }
}  

namespace dds { 
    namespace topic {
        void topic_type_support<Temperateure>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                TemperateurePlugin_new,
                TemperateurePlugin_delete);
        }

        std::vector<char>& topic_type_support<Temperateure>::to_cdr_buffer(
            std::vector<char>& buffer, const Temperateure& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = TemperateurePlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = TemperateurePlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<Temperateure>::from_cdr_buffer(Temperateure& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = TemperateurePlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create Temperateure from cdr buffer");
        }

        void topic_type_support<Temperateure>::reset_sample(Temperateure& sample) 
        {
            rti::topic::reset_sample(sample.currentTemperature());
        }

        void topic_type_support<Temperateure>::allocate_sample(Temperateure& sample, int, int) 
        {
        }

    }
}  

