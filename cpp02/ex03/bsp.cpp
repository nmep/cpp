# include "Point.hpp"

int main(void)
{
	Point P1; //default constructor P1 = (0 ; 0)
	Point P2(4.18f, 3.02f); // Fixed constructor P2 = (4.18 ; 3.02)
	Point P3(P2); // copy constructor P3 = P2 = (4.18 ; 3.02)
	Point P4(94.16f, 100.12f);
	Point P(1.5f, 1.5f); 
	Point P5 = P; // Assignation operator used
	Point P6(-0.5f, -0.5f);
	
	// 2.56 ; 2.08 part of the vertex
	Point Tc(0, 0);
	Point Ta(5.12, 4.16);
	Point Tb(1.18, -6.49);

	Point Tx(0, 3.02);
	Point Ty(5, 3.02);
	Point Tz(2.5, 0);

	// One of the vertexes
	std::cout << std::endl;
	std::cout << "x: " << P1.GetX() << " y: " << P1.GetY() << std::endl;
	std::cout << "BSP Return value: " << bsp(Ta, Tb, Tc, P1) << std::endl;

	std::cout << std::endl;
	std::cout << "x: " << P2.GetX() << " y: " << P2.GetY() << std::endl;
	std::cout << "BSP Return value: " << bsp(Ta, Tb, Tc, P2) << std::endl;

	// On the edge
	std::cout << std::endl;
	std::cout << "x: " << P3.GetX() << " y: " << P3.GetY() << std::endl;
	std::cout << "BSP Return value: " << bsp(Tx, Ty, Tz, P3) << std::endl;

	// Outside the triangle
	std::cout << std::endl;
	std::cout << "x: " << P4.GetX() << " y: " << P4.GetY() << std::endl;
	std::cout << "BSP Return value: " << bsp(Ta, Tb, Tc, P4) << std::endl;

	// On the edge
	std::cout << std::endl;
	std::cout << "x: " << P5.GetX() << " y: " << P5.GetY() << std::endl;
	std::cout << "BSP Return value: " << bsp(Ta, Tb, Tc, P5) << std::endl;

	// Inside
	std::cout << std::endl;
	std::cout << "x: " << P5.GetX() << " y: " << P5.GetY() << std::endl;
	std::cout << "BSP Return value: " << bsp(Tx, Ty, Tz, P5) << std::endl;

	// Outside
	std::cout << std::endl;
	std::cout << "x: " << P6.GetX() << " y: " << P6.GetY() << std::endl;
	std::cout << "BSP Return value: " << bsp(Tx, Ty, Tz, P6) << std::endl;
	return 0; 
}