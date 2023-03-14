// SPDX-FileCopyrightText: 2023 Hiroto Horimoto
// SPDX-License-Identifier: LGPL
// Some lines are derived from https://github.com/ryuichiueda/mcl. // SPDX-FileCopyrightText: 2023 Hiroto Horimoto

#ifndef INTERFACE_H__
#define INTERFACE_H__

#include <ros/ros.h>
#include "gl_mcl/ParticleFilter.h"

#include "tf2_ros/transform_broadcaster.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/message_filter.h"
#include "tf2/LinearMath/Transform.h"

#include "sensor_msgs/LaserScan.h"
#include "sensor_msgs/NavSatFix.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"

class GlMclNode
{
public:
	GlMclNode();
	~GlMclNode();

	void loop(void);
	int getOdomFreq(void);

private:
	std::shared_ptr<ParticleFilter> pf_;
	ros::NodeHandle nh_;
	ros::NodeHandle private_nh_;

	ros::Publisher particlecloud_pub_;
	ros::Publisher pose_pub_;
	ros::Subscriber laser_scan_sub_;
	ros::Subscriber gnss_sub_;
	ros::Subscriber initial_pose_sub_;

	std::string base_frame_id_;
	std::string global_frame_id_;
	std::string odom_frame_id_;

	std::shared_ptr<tf2_ros::TransformBroadcaster> tfb_;
	std::shared_ptr<tf2_ros::TransformListener> tfl_;
	std::shared_ptr<tf2_ros::Buffer> tf_;

	tf2::Transform latest_tf_;

	int odom_freq_;
	bool init_request_;
	double init_x_, init_y_, init_t_;

	void publishPose(double x, double y, double t,
					 double x_dev, double y_dev, double t_dev,
					 double xy_cov, double yt_cov, double tx_cov);
	void publishOdomFrame(double x, double y, double t);
	void publishParticles(void);
	void sendTf(void);
	bool getOdomPose(double &x, double &y, double &yaw);

	void initTF(void);
	void initPF(void);
	void initTopic(void);
	shared_ptr<LikelihoodFieldMap> initMap(void);
	shared_ptr<OdomModel> initOdometry(void);

	void cbGnss(const sensor_msgs::NavSatFix::ConstPtr &msg);
	void cbScan(const sensor_msgs::LaserScan::ConstPtr &msg);
	void initialPoseReceived(const geometry_msgs::PoseWithCovarianceStampedConstPtr &msg);
};

#endif