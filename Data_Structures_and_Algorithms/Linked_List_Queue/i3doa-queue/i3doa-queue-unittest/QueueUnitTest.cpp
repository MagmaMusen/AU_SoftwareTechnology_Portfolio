#include"pch.h"
#include"../i3doa-queue/Queue.h"
#include "../i3doa-queue/LinkedListQueue.h"


class QueueUnitTest : public testing::Test
{
protected:

	void SetUp()
	{
		uut = new LinkedListQueue<int>();
	}

	void TearDown()
	{
		delete uut;
	}

	Queue<int>* uut;
};


TEST_F(QueueUnitTest, Ctor_QueueEmpty)
{
	ASSERT_TRUE(uut->isEmpty());
}

TEST_F(QueueUnitTest, Push_QueueNotEmpty)
{
	uut->push(2);
	ASSERT_FALSE(uut->isEmpty());
}

TEST_F(QueueUnitTest, Push_QueueFrontCorrect)
{
	uut->push(2);
	ASSERT_EQ(uut->front(), 2);
}

TEST_F(QueueUnitTest, Push_Push2Elements_QueueFrontCorrect)
{
	uut->push(2);
	uut->push(3);
	ASSERT_EQ(uut->front(), 2);
}

TEST_F(QueueUnitTest, Pop_PushPop_QueueEmpty)
{
	uut->push(2);
	uut->pop();
	ASSERT_TRUE(uut->isEmpty());
}

TEST_F(QueueUnitTest, Push_Push2ElementsPop1_QueueFrontCorrect)
{
	uut->push(2);
	uut->push(3);
	uut->pop();
	ASSERT_EQ(uut->front(), 3);
}


TEST_F(QueueUnitTest, Pop_QueueEmpty_ExceptionThrown)
{
	ASSERT_THROW(uut->pop(), std::out_of_range);
}


TEST_F(QueueUnitTest, Front_QueueEmpty_ExceptionThrown)
{
	ASSERT_THROW(uut->front(), std::out_of_range);
}


