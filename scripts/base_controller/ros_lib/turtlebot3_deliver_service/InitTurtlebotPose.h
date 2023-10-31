#ifndef _ROS_SERVICE_InitTurtlebotPose_h
#define _ROS_SERVICE_InitTurtlebotPose_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"

namespace turtlebot3_deliver_service
{

static const char INITTURTLEBOTPOSE[] = "turtlebot3_deliver_service/InitTurtlebotPose";

  class InitTurtlebotPoseRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::PoseWithCovarianceStamped _poseWithCovarianceStamped_type;
      _poseWithCovarianceStamped_type poseWithCovarianceStamped;

    InitTurtlebotPoseRequest():
      poseWithCovarianceStamped()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->poseWithCovarianceStamped.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->poseWithCovarianceStamped.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return INITTURTLEBOTPOSE; };
    const char * getMD5(){ return "dd1774f5f4457d898f2470c31d60fe55"; };

  };

  class InitTurtlebotPoseResponse : public ros::Msg
  {
    public:

    InitTurtlebotPoseResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return INITTURTLEBOTPOSE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class InitTurtlebotPose {
    public:
    typedef InitTurtlebotPoseRequest Request;
    typedef InitTurtlebotPoseResponse Response;
  };

}
#endif
