#include "TList.h"
#include <gtest.h>

TEST(TList, can_create_list)
{
  ASSERT_NO_THROW(TList<int> temp);
}

TEST(TList, can_assign_list)
{
  TList<int> temp;
  ASSERT_NO_THROW(TList<int> temp2 = temp);
}

TEST(TList, can_copy_list)
{
  TList<int> temp;
  ASSERT_NO_THROW(TList<int> temp2(temp));
}

TEST(TList, can_get_elem_first)
{
  TList<int> temp;
  ASSERT_NO_THROW(temp.GetEnd());
}

TEST(TList, can_get_elem_last)
{
  TList<int> temp;
  ASSERT_NO_THROW(temp.GetBegin());
}

TEST(TList, can_get_count)
{
  TList<int> temp;
  ASSERT_NO_THROW(temp.GetCount());
}

TEST(TList, can_delete_begin)
{
  TList<int> temp;
  EXPECT_ANY_THROW(temp.DeleteBegin());
}

TEST(TList, can_delete_end)
{
  TList<int> temp;
  EXPECT_ANY_THROW(temp.DeleteEnd());
}