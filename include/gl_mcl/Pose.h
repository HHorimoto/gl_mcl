// SPDX-FileCopyrightText: 2023 Hiroto Horimoto
// SPDX-License-Identifier: LGPL
// Some lines are derived from https://github.com/ryuichiueda/mcl.

#ifndef POSE_H__
#define POSE_H__

#include <sstream>

using namespace std;

class Pose
{
public:
	Pose(double x, double y, double t);

	void set(double x, double y, double t);
	void set(const Pose &p);
	string to_s(void);

	void normalizeAngle(void);
	void move(double length, double direction, double rotation,
			  double fw_noise, double rot_noise);

	Pose operator-(const Pose &p) const;
	Pose operator=(const Pose &p);

	bool nearlyZero(void);

	double x_, y_, t_;
};

#endif
