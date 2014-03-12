// This file is part of V-REP, the Virtual Robot Experimentation Platform.
// 
// Copyright 2006-2014 Dr. Marc Andreas Freese. All rights reserved. 
// marc@coppeliarobotics.com
// www.coppeliarobotics.com
// 
// V-REP is dual-licensed, under the terms of EITHER (at your option):
//   1. V-REP commercial license (contact us for details)
//   2. GNU GPL (see below)
// 
// GNU GPL license:
// -------------------------------------------------------------------
// V-REP is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// V-REP is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with V-REP.  If not, see <http://www.gnu.org/licenses/>.
// -------------------------------------------------------------------
//
// This file was automatically created for V-REP release V3.1.0 on January 20th 2014

#ifndef QDLGCONVEXDECOMPOSITION_H
#define QDLGCONVEXDECOMPOSITION_H

#include "VDialog.h"

namespace Ui {
	class CQDlgConvexDecomposition;
}

class CQDlgConvexDecomposition : public VDialog
{
    Q_OBJECT

public:
	explicit CQDlgConvexDecomposition(QWidget *parent = 0);
	~CQDlgConvexDecomposition();

	void cancelEvent();
	void okEvent();

	void refresh();

	static bool addExtraDistPoints;
	static bool addFacesPoints;
	static int nClusters;
	static int maxHullVertices;
	static float maxConcavity;
	static float smallClusterThreshold;
	static int maxTrianglesInDecimatedMesh;
	static float maxConnectDist;
	static bool individuallyConsiderMultishapeComponents;
	static bool randomColors;
	static int maxIterations;

private slots:

	void on_qqOkCancel_accepted();

	void on_qqOkCancel_rejected();

	void on_qqExtraDistPoints_clicked();

	void on_qqExtraFacesPoints_clicked();

	void on_qqClusters_editingFinished();

	void on_qqConcavity_editingFinished();

	void on_qqConnectDist_editingFinished();

	void on_qqTargetBlabla_editingFinished();

	void on_qqMaxHullVertices_editingFinished();

	void on_qqSmallClusterThreshold_editingFinished();

	void on_qqIndividualComponents_clicked();

	void on_qqRandomColors_clicked();

	void on_qqMaxIterations_editingFinished();

private:
	Ui::CQDlgConvexDecomposition *ui;
};

#endif // QDLGCONVEXDECOMPOSITION_H
