#include "TListNode.h"
#include <gtest.h>

TEST(TListNode, can_create_listnode)
{
  ASSERT_NO_THROW(TListNode<int> temp);
}

TEST(TListNode, can_assign_listnode)
{
  TListNode<int> temp;
  ASSERT_NO_THROW(TListNode<int> temp2 = temp);
}

TEST(TListNode, can_copy_listnode)
{
  TListNode<int> temp;
  ASSERT_NO_THROW(TListNode<int> temp2(temp));
}

TEST(TListNode, can_get_prev)
{
  TListNode<int> temp;
  ASSERT_NO_THROW(temp.GetPrev());
}

TEST(TListNode, can_get_next)
{
  TListNode<int> temp;
  ASSERT_NO_THROW(temp.GetNext());
}

TEST(TListNode, can_get_data)
{
  TListNode<int> temp;
  ASSERT_NO_THROW(temp.GetData());
}

TEST(TListNode, can_nullptr_data)
{
  TListNode<int> temp;
  ASSERT_EQ(temp.GetData(),nullptr);
}

TEST(TListNode, can_nullptr_prev)
{
  TListNode<int> temp;
  ASSERT_EQ(temp.GetPrev(), nullptr);
}

TEST(TListNode, can_nullptr_next)
{
  TListNode<int> temp;
  ASSERT_EQ(temp.GetNext(), nullptr);
}