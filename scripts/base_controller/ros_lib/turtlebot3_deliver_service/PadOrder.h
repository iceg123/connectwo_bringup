#ifndef _ROS_turtlebot3_deliver_service_PadOrder_h
#define _ROS_turtlebot3_deliver_service_PadOrder_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace turtlebot3_deliver_service
{

  class PadOrder : public ros::Msg
  {
    public:
      typedef uint32_t _pad_number_type;
      _pad_number_type pad_number;
      typedef uint32_t _item_number_type;
      _item_number_type item_number;

    PadOrder():
      pad_number(0),
      item_number(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->pad_number >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pad_number >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->pad_number >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->pad_number >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pad_number);
      *(outbuffer + offset + 0) = (this->item_number >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->item_number >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->item_number >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->item_number >> (8 * 3)) & 0xFF;
      offset += sizeof(this->item_number);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->pad_number =  ((uint32_t) (*(inbuffer + offset)));
      this->pad_number |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->pad_number |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->pad_number |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->pad_number);
      this->item_number =  ((uint32_t) (*(inbuffer + offset)));
      this->item_number |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->item_number |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->item_number |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->item_number);
     return offset;
    }

    const char * getType(){ return "turtlebot3_deliver_service/PadOrder"; };
    const char * getMD5(){ return "f312fcf0d154bf3751121cfb69eca080"; };

  };

}
#endif
