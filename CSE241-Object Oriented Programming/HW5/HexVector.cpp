#include <iostream>
#include "HexVector.h"
#include <fstream>
#include <string>
namespace Hex
{
	using namespace std;

	//I control the value
	//Control function
    int HexVector::check_valid(int x, int y, int checkempty) {


    	if (checkempty == 1) {
    		if (hex[x][y] == 46) {
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
    		    		if (hex[x][y] == 120) {
    		    			return 1;
    		    		}
    		    		else return 0;

    		    	}
    		    	if (get_user() == 2) {
    		    		if (hex[x][y] == 111) {
    		    			return 1;
    		    		}
    		    		else return 0;


    		    	}
    	}
    	else if(checkempty== 0)
    	{


    	if (get_user() == 1) {
    		if (hex[x][y] == 46) {
    			return 1;
    		}
    		else return 0;

    	}
    	if (get_user() == 2) {
    		if (hex[x][y] == 46) {
    			return 1;
    		}
    		else return 0;


    	}
    	}

    }
    //It set  size of hextable with using  memberfuction setSize of AbstractHex class
    HexVector::HexVector( int xSize , int ySize ) : AbstractHex()
    {
        setSize( xSize , ySize );
    }
    //Two parameter constructor
    void HexVector::setSize( const int& xSize , const int& ySize )
    {
        if( !hex.empty() )
            hex.clear();
        AbstractHex::setSize( xSize , ySize );
        hex.resize( xSize , std::vector<int> ( ySize , -1 ));
    }
    //It send hex array to AbstractHex class
    int& HexVector::operator()( int x , int y )
    {
        if( (x < 0 || x > (get_xSize() - 1) ) || (y < 0 || y > (get_ySize() - 1) ) )
        {
            cerr << endl << "Invalid argument ! Error , operator() " << endl << endl;

        }
        return hex[ x ][ y ];
    }
    //It send hex array to AbstractHex class
    const int& HexVector::operator()( int x , int y ) const
    {
        if( (x < 0 || x > (get_xSize() - 1) ) || (y < 0 || y > (get_ySize() - 1) ) )
        {
            cerr << endl << "Invalid argument ! Error , operator() " << endl << endl;

        }

        return hex[ x ][ y ];
    }



    HexVector::~HexVector()
    {
        hex.clear();
    }

}
