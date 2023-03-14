// SPDX-FileCopyrightText: 2023 Hiroto Horimoto
// SPDX-License-Identifier: LGPL
// Some lines are derived from https://github.com/ryuichiueda/mcl.

#ifndef GNSS_H__
#define GNSS_H__

class Gnss
{
public:
	int seq_;
	int processed_seq_;
    int status_;
    double lat_;
    double lon_;
	double x_;
    double y_;
};

#endif