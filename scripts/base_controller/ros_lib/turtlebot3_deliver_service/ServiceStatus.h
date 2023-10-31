#ifndef _ROS_turtlebot3_deliver_service_ServiceStatus_h
#define _ROS_turtlebot3_deliver_service_ServiceStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace turtlebot3_deliver_service
{

  class ServiceStatus : public ros::Msg
  {
    public:
      int32_t item_num_chosen_by_pad[3];
      bool is_item_available[3];
      int32_t robot_service_sequence[3];

    ServiceStatus():
      item_num_chosen_by_pad(),
      is_item_available(),
      robot_service_sequence()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint32_t i = 0; i < 3; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_item_num_chosen_by_padi;
      u_item_num_chosen_by_padi.real = this->item_num_chosen_by_pad[i];
      *(outbuffer + offset + 0) = (u_item_num_chosen_by_padi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_item_num_chosen_by_padi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_item_num_chosen_by_padi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_item_num_chosen_by_padi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->item_num_chosen_by_pad[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        bool real;
        uint8_t base;
      } u_is_item_availablei;
      u_is_item_availablei.real = this->is_item_available[i];
      *(outbuffer + offset + 0) = (u_is_item_availablei.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_item_available[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_robot_service_sequencei;
      u_robot_service_sequencei.real = this->robot_service_sequence[i];
      *(outbuffer + offset + 0) = (u_robot_service_sequencei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_robot_service_sequencei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_robot_service_sequencei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_robot_service_sequencei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->robot_service_sequence[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint32_t i = 0; i < 3; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_item_num_chosen_by_padi;
      u_item_num_chosen_by_padi.base = 0;
      u_item_num_chosen_by_padi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_item_num_chosen_by_padi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_item_num_chosen_by_padi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_item_num_chosen_by_padi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->item_num_chosen_by_pad[i] = u_item_num_chosen_by_padi.real;
      offset += sizeof(this->item_num_chosen_by_pad[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        bool real;
        uint8_t base;
      } u_is_item_availablei;
      u_is_item_availablei.base = 0;
      u_is_item_availablei.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_item_available[i] = u_is_item_availablei.real;
      offset += sizeof(this->is_item_available[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_robot_service_sequencei;
      u_robot_service_sequencei.base = 0;
      u_robot_service_sequencei.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_robot_service_sequencei.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_robot_service_sequencei.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_robot_service_sequencei.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->robot_service_sequence[i] = u_robot_service_sequencei.real;
      offset += sizeof(this->robot_service_sequence[i]);
      }
     return offset;
    }

    const char * getType(){ return "turtlebot3_deliver_service/ServiceStatus"; };
    const char * getMD5(){ return "88c792271484968782eee6bf1d95c178"; };

  };

}
#endif
