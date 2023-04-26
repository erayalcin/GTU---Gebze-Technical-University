#ifndef Abs_Hex
#define Abs_Hex
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using std::string;
using namespace std;
namespace Hex
{
	class AbstractHex
	{
		public:

	            AbstractHex(void);
	            std::vector<std::vector<int>> solve;
	           void fillArray();
	           bool checkFull();
	           void fillSolveArray();
	           void print() const;
	           int determineWin(int x,int y);
	           void readFile(const string& filename);
	           void writeFile(const string& filename);
	           int play();
	           void reset();
	           void set_computerx(int comx);
	           void set_computery(int comy);
	           int get_computerx();
	           int get_computery();
	           int numbermoves();
	            virtual void setSize( const int& xSize , const int& ySize );
	            void  setSelection(const int& selection);
	            void  setUser(const int& user);
	            int BeforeStartPlaying();
	            int play(int x,int y);
	            bool isEnd(int x,int y);
	            virtual int& operator()(int x , int y) = 0;
	            virtual int check_valid( int x , int y ,int checkempty)=0;
	            virtual const int& operator()(int x , int y) const = 0;
	            int get_xSize(void) const { return xSize; }
	            int get_ySize(void) const { return ySize; }
	            int get_selection(void) const { return selection; }
	            int get_user(void) const { return user; }

	            virtual ~AbstractHex();

	        private:

	            int xSize,ySize,selection,user,computerx,computery,numberofmoves; /* Blank representation */
	            char lastmove;              /* Last move */





};
}

#endif
