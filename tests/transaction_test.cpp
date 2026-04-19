#include "Account.h"
#include "Transaction.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::_;
using ::testing::Return;

class MockAccount : public Account {
 public:
  MockAccount(int id, int balance) : Account(id, balance) {}

  MOCK_METHOD(int, GetBalance, (), (const, override));
  MOCK_METHOD(void, ChangeBalance, (int), (override));
  MOCK_METHOD(void, Lock, (), (override));
  MOCK_METHOD(void, Unlock, (), (override));
};

class MockTransaction : public Transaction {
 public:
  MOCK_METHOD(void, SaveToDataBase, (Account& from, Account& to, int sum), (override));
};

TEST(Transaction, ThrowsOnSameAccount) {
  Transaction transaction;
  Account account(1, 1000);
  EXPECT_THROW(transaction.Make(account, account, 100), std::logic_error);
}

TEST(Transaction, ThrowsOnNegativeSum) {
  Transaction transaction;
  Account from(1, 1000);
  Account to(2, 1000);
  EXPECT_THROW(transaction.Make(from, to, -100), std::invalid_argument);
}

TEST(Transaction, ThrowsOnSmallSum) {
  Transaction transaction;
  Account from(1, 1000);
  Account to(2, 1000);
  EXPECT_THROW(transaction.Make(from, to, 50), std::logic_error);
}

TEST(Transaction, ReturnsFalseWhenFeeIsTooLarge) {
  Transaction transaction;
  Account from(1, 1000);
  Account to(2, 1000);
  transaction.set_fee(60);
  EXPECT_FALSE(transaction.Make(from, to, 100));
}

TEST(Transaction, ReturnsFalseWhenSourceBalanceIsNotEnough) {
  MockTransaction transaction;
  MockAccount from(1, 1000);
  MockAccount to(2, 500);

  EXPECT_CALL(from, Lock());
  EXPECT_CALL(to, Lock());
  EXPECT_CALL(from, Unlock());
  EXPECT_CALL(to, Unlock());
  EXPECT_CALL(from, GetBalance()).WillOnce(Return(100));
  EXPECT_CALL(from, ChangeBalance(_)).Times(0);
  EXPECT_CALL(to, ChangeBalance(_)).Times(0);
  EXPECT_CALL(transaction, SaveToDataBase(_, _, _)).Times(0);

  EXPECT_FALSE(transaction.Make(from, to, 200));
}

TEST(Transaction, TransfersMoneyAndSavesToDatabase) {
  MockTransaction transaction;
  MockAccount from(1, 1000);
  MockAccount to(2, 500);
  transaction.set_fee(50);

  EXPECT_CALL(from, Lock());
  EXPECT_CALL(to, Lock());
  EXPECT_CALL(from, Unlock());
  EXPECT_CALL(to, Unlock());
  EXPECT_CALL(from, GetBalance()).WillOnce(Return(1000));
  EXPECT_CALL(from, ChangeBalance(-250));
  EXPECT_CALL(to, ChangeBalance(200));
  EXPECT_CALL(transaction, SaveToDataBase(_, _, 200));

  EXPECT_TRUE(transaction.Make(from, to, 200));
}
