/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 #include<iostream>
 using namespace std;
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest, dropTest)
{
	Piezas p;
    cout<<"first turn "<<p.dropPiece(0)<<endl;
	ASSERT_TRUE(p.pieceAt(0,0) == 88);
}
TEST(PiezaTest, switchTest)
{
	Piezas p;
	p.dropPiece(0);
	p.dropPiece(0);
	ASSERT_TRUE(p.pieceAt(1,0) == 79);
}
TEST(PiezaTest, resetTest)
{
	Piezas p;
	p.dropPiece(0);
	p.reset();
	ASSERT_TRUE(p.pieceAt(1,0) == 32);
}

TEST(PiezaTest, invalidDrop)
{
	Piezas p;
	ASSERT_TRUE(p.dropPiece(4) == 63);
}

TEST(PiezaTest, loseTurnifMoveInvalid)
{
	Piezas p;
	p.dropPiece(0);
	p.dropPiece(0);
	p.dropPiece(0);
	p.dropPiece(0);
	p.dropPiece(1);
	//cout<<p.pieceAt(2,0)<<endl;
	//cout<<p.pieceAt(0,1)<<endl;
	ASSERT_TRUE(p.pieceAt(2,0) == p.pieceAt(0,1));
}
TEST(PiezaTest, dropBlankifFull)
{
	Piezas p;
	p.dropPiece(0);
	p.dropPiece(0);
	p.dropPiece(0);
	ASSERT_TRUE(p.dropPiece(0) == 32);
}
TEST(PiezaTest, rowWinner)
{
	Piezas p;
	p.dropPiece(0);
	p.dropPiece(1);
	
	p.dropPiece(2);
	p.dropPiece(1);
	
	p.dropPiece(1);
	p.dropPiece(0);
	
	p.dropPiece(3);
	p.dropPiece(2);
	
	p.dropPiece(3);
	p.dropPiece(3);
	
	p.dropPiece(2);
	p.dropPiece(0);
	
	//cout<<p.gameState()<<endl;
	ASSERT_TRUE(p.gameState() == 79);
}

TEST(PiezaTest, gameNotOver)
{
	Piezas p;
	p.dropPiece(0);
	p.dropPiece(1);
	p.dropPiece(0);
	p.dropPiece(1);
	p.dropPiece(0);
	p.dropPiece(2);
	p.dropPiece(1);
	p.dropPiece(2);


	//cout<<p.gameState()<<endl;
	ASSERT_TRUE(p.gameState() == 63);
}

TEST(PiezaTest, colWinner)
{
	Piezas p;
	p.dropPiece(0);
	p.dropPiece(3);
	
	p.dropPiece(2);
	p.dropPiece(1);
	
	p.dropPiece(0);
	p.dropPiece(2);
	
	p.dropPiece(1);
	p.dropPiece(1);
	
	p.dropPiece(0);
	p.dropPiece(3);
	
	p.dropPiece(3);
	p.dropPiece(2);
	
	//cout<<p.gameState()<<endl;
	
	ASSERT_TRUE(p.gameState() == 88);
}
