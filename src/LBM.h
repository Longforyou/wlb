/*
 * LBM-D2Q9.h
 * Andreas B�lling, 2012
 *
 */

#ifndef LBM_H_
#define LBM_H_


#include <iostream>
#include <list>
#include <string.h>
#include <sstream>
#include <cstdio>
#include <sys/stat.h>
#include <sys/types.h>
#include <math.h>

#include "Constants.h"
#include "Aux.h"

#include "bdr/BoundaryNodes.h"
#include "bdr/HalfWayBBNodes.h"
#include "bdr/Node.h"
#include "bdr/NodeNeighbors.h"
#include "bdr/BounceBackNodes.h"
#include "bdr/HeZouPressureNodes.h"
#include "bdr/DirichletLPMNodes.h"
#include "bdr/NeumannLPMNodes.h"
//#include "BFLBoundaryNodes.h"
//#include "ConstantPressureBoundaryNodes.h"
//#include "ConstantVelocityBoundaryNodes.h"

#include "str/StreamModel.h"
//#include "str/PeriodicStreamModel.h"
//#include "str/DefaultStreamModel.h"
#include "str/StreamD2Q9.h"
#include "str/StreamD2Q9Periodic.h"

#include "col/CollisionModel.h"
#include "col/CollisionD2Q9.h"
#include "col/CollisionD2Q9BGK.h"
#include "col/CollisionD2Q9LPM.h"
#include "col/CollisionD2Q9LPMChai.h"

#include "lat/Lattice2D.h"
#include "lat/LatticeModel.h"

using namespace std;


class LBM{
private:
	int nx;
	int ny;
	double ****f;
	double ***rho;
	double ***ux;
	double ***uy;
	double ***uz;
	bool **deadNodes;
	HalfWayBBNodes *hwbbNodes;
	vector<BoundaryNodes*> boundaryNodes;
	//BFLBoundaryNodes *bflNodes;
	//ConstantPressureBoundaryNodes *cpNodes;
	//ConstantVelocityBoundaryNodes *cvNodes;
	StreamModel *streamModel;
	CollisionModel *collisionModel;
	LatticeModel *latticeModel;
public:
	LBM(LatticeModel *lm, CollisionModel *c, StreamModel *sm);
	void init();
	void initVelocity(double **uxInit, double **uyInit);
	void initRho(double **rhoInit);

	void calcMacroscopicVars();
	void handleWetBoundaries();
	void handleHardBoundaries();
	void handleBoundaries();

	void printfi(int n);
	void printu();
	void dataToFile();

	void addHalfWayBBNodes(HalfWayBBNodes *bbn);
	void addBoundaryNodes(BoundaryNodes *bn);

	void setStreamModel(StreamModel *s);
	void setCollisionModel(CollisionModel *cm);
	void setLatticeModel(LatticeModel *lm);

	void collideAndStream();
	//void setW(double w);
	//void setC(double c);
	//void setF(double fxi, double fyi, int x, int y);
	//double Si(int d, int i, int j);
	//double Si2(int d, int i, int j);
	//double ***getRho();
	//int getNx();
	//int getNy();
	//void addBFLNodes(BFLBoundaryNodes *bfl);
	//void addConstantPressureBoundaryNodes(ConstantPressureBoundaryNodes *cpn);
	//void addConstantVelocityBoundaryNodes(ConstantVelocityBoundaryNodes *cpn);
	//void clearConstantVelocityBoundaryNodes();
	//void addDeadNode(int x, int y);
};

#endif /* LBM_H_ */
