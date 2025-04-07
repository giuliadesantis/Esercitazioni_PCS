#include <iostream>
#include "Eigen/Eigen"
#include <iomanip>

using namespace std;
using namespace Eigen;

double err_rel(const Vector2d& x_es, const Vector2d& x_err) {
	return (x_err - x_es).norm() / x_es.norm();
}

VectorXd sol_PALU(const MatrixXd& A, const VectorXd& b){
	VectorXd sol_PALU =  A.partialPivLu().solve(b);
	return sol_PALU;
}

VectorXd sol_QR(const MatrixXd& A, const VectorXd& b){
	VectorXd sol_QR =  A.householderQr().solve(b);
	return sol_QR;
}


int main()
{
	Vector2d x_es(-1.0e+00, -1.0e+00);
	double epsilon = 10e-15;
	
	cout << "Sistema 1" << endl;
	
	Matrix2d A1 {
		{5.547001962252291e-01, -3.770900990025203e-02},
		{8.320502943378437e-01, -9.992887623566787e-01},
	};
	Vector2d b1(-5.169911863249772e-01, 1.672384680188350e-01);
	double err_PALU, err_QR;
	
	if (abs(A1.determinant()) < epsilon) {
        cout << "La matrice è singolare (determinante ≈ 0)." <<endl;
    } else {
		cout << "soluzione PALU:\n" << scientific << setprecision(15) << sol_PALU(A1,b1) << endl;
		err_PALU = err_rel(x_es,sol_PALU(A1,b1));
		cout << "errore relativo PALU: " << scientific << setprecision(15)<< err_PALU << endl;
		
		cout << "soluzione QR: \n" << scientific << setprecision(15)<< sol_QR(A1,b1) << endl;
		err_QR = err_rel(x_es,sol_QR(A1,b1));
		cout << "errore relativo QR: "<< scientific << setprecision(15) << err_QR << endl;	
	}
	
	cout << "Sistema 2" << endl;
	
	Matrix2d A2 {
		{5.547001962252291e-01, -5.540607316466765e-01},
		{8.320502943378437e-01, -8.324762492991313e-01},
	};
	Vector2d b2(-6.394645785530173e-04, 4.259549612877223e-04);
	
	if (abs(A2.determinant()) < epsilon) {
        cout << "La matrice è singolare (determinante ≈ 0)." <<endl;
    } else {
		cout << "soluzione PALU: \n" << scientific << setprecision(15)<< sol_PALU(A2,b2) << endl;
		err_PALU = err_rel(x_es,sol_PALU(A2,b2));
		cout << "errore relativo PALU: " << scientific << setprecision(15)<< err_PALU << endl;
		
		cout << "soluzione QR: \n" << scientific << setprecision(15)<< sol_QR(A2,b2) << endl;
		err_QR = err_rel(x_es,sol_QR(A2,b2));
		cout << "errore relativo QR: " << scientific << setprecision(15)<< err_QR << endl;
	}	
	
	cout << "Sistema 3" << endl;
	
	Matrix2d A3 {
		{5.547001962252291e-01, -5.547001955851905e-01},
		{8.320502943378437e-01, -8.320502947645361e-01},
	};
	Vector2d b3(-6.400391328043042e-10, 4.266924591433963e-10);
	
	if (abs(A3.determinant()) < epsilon) {
        cout << "La matrice è singolare (determinante ≈ 0)." <<endl;
    } else {
		cout << "soluzione PALU: \n" << scientific << setprecision(15)<< sol_PALU(A3,b3) << endl;
		err_PALU = err_rel(x_es,sol_PALU(A3,b3));
		cout << "errore relativo PALU: " << scientific << setprecision(15)<< err_PALU << endl;
		
		cout << "soluzione QR:\n" << scientific << setprecision(15)<< sol_QR(A3,b3) << endl;
		err_QR = err_rel(x_es,sol_QR(A3,b3));
		cout << "errore relativo QR: " << scientific << setprecision(15)<< err_QR << endl;
	}
		
	
	return 0;
}



