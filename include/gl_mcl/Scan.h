// SPDX-FileCopyrightText: 2023 Hiroto Horimoto
// SPDX-License-Identifier: LGPL
// Some lines are derived from https://github.com/ryuichiueda/mcl.

#ifndef SCAN_H__
#define SCAN_H__

#include <vector>
class Scan
{
public:
	int seq_;
	int processed_seq_;
	double angle_max_;
	double angle_min_;
	double angle_increment_;
	std::vector<double> ranges_;
};

#endif
