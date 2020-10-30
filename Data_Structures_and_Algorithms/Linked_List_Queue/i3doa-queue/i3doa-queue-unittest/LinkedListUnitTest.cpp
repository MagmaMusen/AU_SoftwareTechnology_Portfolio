#include "pch.h"
#include"../i3doa-queue/linkedlist.h"

class LinkedListTest : public testing::Test
{
protected:

	void SetUp()
	{
	}

	void TearDown()
	{
	}

	LinkedList<int> uut;
};

TEST_F(LinkedListTest, Ctor_SizeCorrect)
{
	ASSERT_EQ(0, uut.length());
}



TEST_F(LinkedListTest, HeadInsert_HeadInsertInsertOne_ContentsAndLengthOK)
{
	uut.headInsert(10);
	ASSERT_EQ(10, uut[0]);
	ASSERT_EQ(1, uut.length());
}

TEST_F(LinkedListTest, HeadInsert_HeadInsertTwo_ContentsAndLengthOK)
{
	uut.headInsert(10);
	uut.headInsert(20);

	ASSERT_EQ(2, uut.length());
	ASSERT_EQ(20, uut[0]);
	ASSERT_EQ(10, uut[1]);
}


TEST_F(LinkedListTest, HeadRemove_HeadInsertTwoRemoveOne_ContentsAndLengthOK)
{
	uut.headInsert(10);
	uut.headInsert(20);
	uut.headRemove();
	ASSERT_EQ(1, uut.length());
	ASSERT_EQ(10, uut[0]);
}

TEST_F(LinkedListTest, HeadRemove_HeadInsertOneRemoveOne_ListIsEmpty)
{
	uut.headInsert(10);
	uut.headRemove();
	ASSERT_EQ(0, uut.length());
}

TEST_F(LinkedListTest, HeadRemove_InsertTwoRemoveTwo_ListIsEmpty)
{
	uut.headInsert(10);
	uut.headInsert(20);
	uut.headRemove();
	uut.headRemove();

	ASSERT_EQ(0, uut.length());
}

TEST_F(LinkedListTest, Clear_TwoElementsInList_ListLengthOK)
{
	uut.headInsert(10);
	uut.headInsert(20);
	uut.clear();

	ASSERT_EQ(0, uut.length());
}

TEST_F(LinkedListTest, Insert_FirstElement_ContentsAndLengthOK)
{
	uut.headInsert(10);
	uut.headInsert(20);
	uut.insert(30, 0);

	ASSERT_EQ(3, uut.length());

	ASSERT_EQ(30, uut[0]);
	ASSERT_EQ(20, uut[1]);
	ASSERT_EQ(10, uut[2]);
}


TEST_F(LinkedListTest, Insert_LastElement_ContentsAndLengthOK)
{
	uut.headInsert(10);
	uut.headInsert(20);
	uut.insert(30, 2);

	ASSERT_EQ(3, uut.length());

	ASSERT_EQ(20, uut[0]);
	ASSERT_EQ(10, uut[1]);
	ASSERT_EQ(30, uut[2]);
}

TEST_F(LinkedListTest, Insert_InvalidIndex_ExceptionThrown)
{
	uut.headInsert(10);
	uut.headInsert(20);
	ASSERT_THROW(
		uut.insert(30, 3),
		std::out_of_range
	);
}



TEST_F(LinkedListTest, Remove_FirstElement_ContentsAndLengthOK)
{
	uut.headInsert(10);
	uut.headInsert(20);
	uut.headInsert(30);
	uut.remove(0);

	ASSERT_EQ(2, uut.length());

	ASSERT_EQ(20, uut[0]);
	ASSERT_EQ(10, uut[1]);
}

TEST_F(LinkedListTest, Remove_LastElement_ContentsAndLengthOK)
{
	uut.headInsert(10);
	uut.headInsert(20);
	uut.headInsert(30);
	uut.remove(2);

	ASSERT_EQ(2, uut.length());

	ASSERT_EQ(30, uut[0]);
	ASSERT_EQ(20, uut[1]);
}


TEST_F(LinkedListTest, Remove_Invalidindex_ExceptionThrown)
{
	uut.headInsert(10);
	uut.headInsert(20);
	uut.headInsert(30);
	ASSERT_THROW(
		uut.remove(3),
		std::out_of_range
	);
}


TEST_F(LinkedListTest, CopyCtor_CopyContentsAndLengthOK)
{
	uut.headInsert(10);
	uut.headInsert(20);
	uut.headInsert(30);

	LinkedList<int> uut2(uut);

	ASSERT_EQ(3, uut2.length());

	ASSERT_EQ(30, uut2[0]);
	ASSERT_EQ(20, uut2[1]);
	ASSERT_EQ(10, uut2[2]);
}

TEST_F(LinkedListTest, CopyCtor_RemoveFromOriginal_CopyContentsAndLengthOK)
{
	uut.headInsert(10);
	uut.headInsert(20);
	uut.headInsert(30);

	LinkedList<int> uut2(uut);

	uut.headRemove();
	uut.headRemove();

	ASSERT_EQ(3, uut2.length());

	ASSERT_EQ(30, uut2[0]);
	ASSERT_EQ(20, uut2[1]);
	ASSERT_EQ(10, uut2[2]);
}

TEST_F(LinkedListTest, CopyCtor_RemoveFromCopy_CopyContentsAndLengthChanged)
{
	uut.headInsert(10);
	uut.headInsert(20);
	uut.headInsert(30);

	LinkedList<int> uut2(uut);

	uut2.headRemove();
	uut2.headRemove();

	ASSERT_EQ(1, uut2.length());

	ASSERT_EQ(10, uut2[0]);
}

TEST_F(LinkedListTest, CopyCtor_RemoveFromCopy_OriginalContentsAndLengthOK)
{
	uut.headInsert(10);
	uut.headInsert(20);
	uut.headInsert(30);

	LinkedList<int> uut2(uut);

	uut2.headRemove();
	uut2.headRemove();

	ASSERT_EQ(3, uut.length());

	ASSERT_EQ(30, uut[0]);
	ASSERT_EQ(20, uut[1]);
	ASSERT_EQ(10, uut[2]);
}



TEST_F(LinkedListTest, Assignment_CopyContentsAndLengthOK)
{
	uut.headInsert(10);
	uut.headInsert(20);
	uut.headInsert(30);

	LinkedList<int> uut2 = uut;

	ASSERT_EQ(3, uut2.length());

	ASSERT_EQ(30, uut2[0]);
	ASSERT_EQ(20, uut2[1]);
	ASSERT_EQ(10, uut2[2]);
}

TEST_F(LinkedListTest, Assignment_RemoveFromOriginal_CopyContentsAndLengthOK)
{
	uut.headInsert(10);
	uut.headInsert(20);
	uut.headInsert(30);

	LinkedList<int> uut2 = uut;

	uut.headRemove();
	uut.headRemove();

	ASSERT_EQ(3, uut2.length());

	ASSERT_EQ(30, uut2[0]);
	ASSERT_EQ(20, uut2[1]);
	ASSERT_EQ(10, uut2[2]);
}

TEST_F(LinkedListTest, Assignment_RemoveFromCopy_CopyContentsAndLengthChanged)
{
	uut.headInsert(10);
	uut.headInsert(20);
	uut.headInsert(30);

	LinkedList<int> uut2(uut);

	uut2.headRemove();
	uut2.headRemove();

	ASSERT_EQ(1, uut2.length());

	ASSERT_EQ(10, uut2[0]);
}

TEST_F(LinkedListTest, Assignment_RemoveFromCopy_OriginalContentsAndLengthOK)
{
	uut.headInsert(10);
	uut.headInsert(20);
	uut.headInsert(30);

	LinkedList<int> uut2 = uut;

	uut2.headRemove();
	uut2.headRemove();

	ASSERT_EQ(3, uut.length());

	ASSERT_EQ(30, uut[0]);
	ASSERT_EQ(20, uut[1]);
	ASSERT_EQ(10, uut[2]);
}



TEST_F(LinkedListTest, Indexing_IndexOutOfRange_ExceptionThrown)
{
	uut.headInsert(10);
	ASSERT_THROW(
		uut[2],
		std::out_of_range
	);
}


TEST_F(LinkedListTest, TailInsert_VanillaListInsertOn_ContentsAndLengthOK)
{
	uut.tailInsert(10);

	ASSERT_EQ(1, uut.length());
	ASSERT_EQ(10, uut[0]);
}

TEST_F(LinkedListTest, TailInsert_HeadInsertOneTailInsertOne_ContentsAndLengthOK)
{
	uut.headInsert(10);
	uut.tailInsert(20);

	ASSERT_EQ(2, uut.length());
	ASSERT_EQ(10, uut[0]);
	ASSERT_EQ(20, uut[1]);
}

TEST_F(LinkedListTest, TailInsert_InsertTwo_ContentsAndLengthOK)
{
	uut.tailInsert(10);
	uut.tailInsert(20);

	ASSERT_EQ(2, uut.length());
	ASSERT_EQ(10, uut[0]);
	ASSERT_EQ(20, uut[1]);
}

TEST_F(LinkedListTest, TailInsert_HeadInsertOneTailInsertTwo_ContentsAndLengthOK)
{
	uut.headInsert(10);
	uut.tailInsert(20);
	uut.tailInsert(30);

	ASSERT_EQ(3, uut.length());
	ASSERT_EQ(10, uut[0]);
	ASSERT_EQ(20, uut[1]);
	ASSERT_EQ(30, uut[2]);
}

TEST_F(LinkedListTest, TailInsert_HeadInsertTwoTailInsertTwo_ContentsAndLengthOK)
{
	uut.headInsert(10);
	uut.tailInsert(20);
	uut.headInsert(40);
	uut.tailInsert(30);

	ASSERT_EQ(4, uut.length());
	ASSERT_EQ(40, uut[0]);
	ASSERT_EQ(10, uut[1]);
	ASSERT_EQ(20, uut[2]);
	ASSERT_EQ(30, uut[3]);
}

TEST_F(LinkedListTest, TailInsert_InsertInMiddle_TailOK)
{
	uut.tailInsert(10);
	uut.tailInsert(20);
	uut.insert(30, 1);
	uut.tailInsert(40);

	ASSERT_EQ(4, uut.length());
	ASSERT_EQ(10, uut[0]);
	ASSERT_EQ(30, uut[1]);
	ASSERT_EQ(20, uut[2]);
	ASSERT_EQ(40, uut[3]);
}