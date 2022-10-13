#include<ilcplex/ilocplex.h>
#include<ilconcert/ilotupleset.h>
#include<iostream>

int main() {
	IloEnv env;
	IloModel model(env);
	IloNumVar X(env, 0, IloInfinity, ILOFLOAT);
	IloNumVar Y(env, 0, IloInfinity, ILOFLOAT);

	model.add(IloMaximize(env, 3 * X + 4 * Y));
	model.add(X + 2 * Y <= 14);
	model.add(3*X - Y >= 0);
	model.add(X - Y <= 2);

	IloCplex cplex(model);
	cplex.solve();

	float objval = cplex.getObjValue();
	float X_val = cplex.getValue(X);
	float Y_val = cplex.getValue(Y);
	
	std::ofstream output;
	output.open("output.txt");
	output << objval << "\n" << X_val << "\n" << Y_val << "\n";
	output.close();
}
