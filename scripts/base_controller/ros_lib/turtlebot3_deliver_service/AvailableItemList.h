#ifndef _ROS_turtlebot3_deliver_service_AvailableItemList_h
#define _ROS_turtlebot3_deliver_service_AvailableItemList_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace turtlebot3_deliver_service
{

  class AvailableItemList : public ros::Msg
  {
    public:
      typedef uint32_t _item_number_type;
      _item_number_type item_number;
      typedef bool _is_item_available_type;
      _is_item_available_type is_item_available;

    AvailableItemList():
      item_number(0),
      is_item_available(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->item_number >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->item_number >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->item_number >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->item_number >> (8 * 3)) & 0xFF;
      offset += sizeof(this->item_number);
      union {
        bool real;
        uint8_t base;
      } u_is_item_available;
      u_is_item_available.real = this->is_item_available;
      *(outbuffer + offset + 0) = (u_is_item_available.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_item_available);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->item_number =  ((uint32_t) (*(inbuffer + offset)));
      this->item_number |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->item_number |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->item_number |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->item_number);
      union {
        bool real;
        uint8_t base;
      } u_is_item_available;
      u_is_item_available.base = 0;
      u_is_item_available.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_item_available = u_is_item_available.real;
      offset += sizeof(this->is_item_available);
     return offset;
    }

    const char * getType(){ return "turtlebot3_deliver_service/AvailableItemList"; };
    const char * getMD5(){ return "4c8abaae09f0bffda0bd8946d2c8b728"; };

  };

}
#endif
