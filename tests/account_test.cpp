#include "Account.h"

#include <gtest/gtest.h>

TEST(Account, BalanceIsReturnedAfterConstruction) {
  Account account(1, 100);
  EXPECT_EQ(account.id(), 1);
  EXPECT_EQ(account.GetBalance(), 100);
}

TEST(Account, ChangeBalanceRequiresLock) {
  Account account(1, 100);
  EXPECT_THROW(account.ChangeBalance(50), std::runtime_error);
}

TEST(Account, LockedAccountCanChangeBalance) {
  Account account(1, 100);
  account.Lock();
  account.ChangeBalance(25);
  EXPECT_EQ(account.GetBalance(), 125);
}

TEST(Account, DoubleLockThrows) {
  Account account(1, 100);
  account.Lock();
  EXPECT_THROW(account.Lock(), std::runtime_error);
}

TEST(Account, UnlockAfterLockAllowsFutureLock) {
  Account account(1, 100);
  account.Lock();
  account.Unlock();
  EXPECT_NO_THROW(account.Lock());
}
