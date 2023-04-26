#include "HexArray1D.h"

namespace Hex {


HexArray1D::HexArray1D(int xSize, int ySize) :
		AbstractHex(), hex(nullptr) {
	setSize(xSize, ySize);

	/* Intentionally left blank */
}



void HexArray1D::setSize(const int& xSize, const int& ySize) {
	if (hex != nullptr) {
		delete[] hex;
		hex = nullptr;
	}

	/* Base class virtual call */
	AbstractHex::setSize(xSize, ySize);
	hex = new int[xSize * ySize];

	/* Whatever is goint to be built */

}

int& HexArray1D::operator()(int x, int y) {
	if ((x < 0 || x > (get_xSize() - 1)) || (y < 0 || y > (get_ySize() - 1))) {
		cerr << endl << "Invalid argument ! Error , operator() " << endl
				<< endl;
		// exit(1);
	}

	return hex[y * get_xSize() + x];
}
int HexArray1D::check_valid(int x, int y, int checkempty) {


	if (checkempty == 1) {
	    		if (hex[y * get_xSize() + x] == 46) {
	    			return 1;
	    		}
	    		else
	    		{
	    			cerr<<"\nThis cell is non empty.\n";
	    			AbstractHex::BeforeStartPlaying();
	    		}

	    	}
	    	else if(checkempty== 2)
	    	{
	    		if (get_user() == 1) {
	    		    		if (hex[y * get_xSize() + x] == 120) {
	    		    			return 1;
	    		    		}
	    		    		else return 0;

	    		    	}
	    		    	if (get_user() == 2) {
	    		    		if (hex[y * get_xSize() + x] == 111) {
	    		    			return 1;
	    		    		}
	    		    		else return 0;
	    		    		//else AbstractHex::BeforeStartPlaying();

	    		    	}
	    	}
	    	else if(checkempty== 0)
	    	{


	    	if (get_user() == 1) {
	    		if (hex[y * get_xSize() + x] == 46) {
	    			return 1;
	    		}
	    		else return 0;

	    	}
	    	if (get_user() == 2) {
	    		if (hex[y * get_xSize() + x] == 46) {
	    			return 1;
	    		}
	    		else return 0;
	    		//else AbstractHex::BeforeStartPlaying();

	    	}
	    	}

}

const int& HexArray1D::operator()(int x, int y) const {
	if ((x < 0 || x > (get_xSize() - 1)) || (y < 0 || y > (get_ySize() - 1))) {
		cerr << endl << "Invalid argument ! Error , operator() " << endl
				<< endl;
		//exit(1);
	}

	return hex[y * get_xSize() + x];
}



HexArray1D::~HexArray1D() {
	delete[] hex;
	hex = nullptr;
}

}
