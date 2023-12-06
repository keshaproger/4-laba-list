#include "TListIterator.h"
#include <gtest.h>

TEST(TListIterator, can_create_listiterator)
{
  ASSERT_NO_THROW(TListIterator<int> temp);
}

TEST(TListIterator, can_assign_listiterator)
{
  TListIterator<int> temp;
  ASSERT_NO_THROW(TListIterator<int> temp2 = temp);
}

TEST(TListIterator, can_copy_listIterator)
{
  TListIterator<int> temp;
  ASSERT_NO_THROW(TListIterator<int> temp2(temp));
}

TEST(TListIterator, cant_push_nul_after_listIterator)
{
  TListIterator<int> temp;
  int* temp1=nullptr;
  ASSERT_ANY_THROW(temp.PushAfter(temp1));
}

TEST(TListIterator, cant_push_null_before_listIterator)
{
  TListIterator<int> temp;
  int* temp1=nullptr;
  ASSERT_ANY_THROW(temp.PushBefore(temp1));
}
