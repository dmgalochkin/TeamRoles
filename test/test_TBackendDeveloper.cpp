#include "TBackendDeveloper.h"
#include <gtest.h>



TEST(BackendDeveloper, CreateWithValidParameters) {
  std::string langs[] = {"C++", "Python"};
  std::string dbs[] = {"PostgreSQL"};
  std::string containers[] = {"Docker"};

  ASSERT_NO_THROW(
    TBackendDeveloper dev(
    30, 150000, "John", 5, 2,
    2, langs, "CLion",
    1, dbs, 1, containers
    )
  );
}

TEST(BackendDeveloper, GetBasicProperties) {
  TBackendDeveloper dev;

  EXPECT_EQ(dev.GetRole(), "BackendDeveloper");
  EXPECT_EQ(dev.GetAge(), 25);
  EXPECT_EQ(dev.GetNumberOfDatabases(), 0);
}

TEST(BackendDeveloper, ThrowsWhenNegativeDatabases) {
  std::string langs[] = {"C++"};
  std::string dbs[] = {"MySQL"};
  std::string containers[] = {"Podman"};

  ASSERT_ANY_THROW(
    TBackendDeveloper dev(
    25, 100000, "Alice", 4, 1,
    1, langs, "VSCode",
    -1, dbs, 1, containers
    )
  );
}

TEST(BackendDeveloper, SetDatabases) {
  TBackendDeveloper dev;
  std::string new_dbs[] = {"Redis", "MongoDB"};

  ASSERT_NO_THROW(dev.SetDatabases(2, new_dbs));
  EXPECT_EQ(dev.GetNumberOfDatabases(), 2);
}

TEST(BackendDeveloper, CopyConstructorWorks) {
  std::string langs[] = {"Go"};
  std::string dbs[] = {"Cassandra"};
  std::string containers[] = {"Kubernetes"};

  TBackendDeveloper orig(
    35, 200000, "Mike", 7, 3,
    1, langs, "GoLand",
    1, dbs, 1, containers
  );

  TBackendDeveloper copy(orig);

  EXPECT_EQ(copy.GetName(), "Mike");
  EXPECT_EQ(copy.GetNumberOfContainers(), 1);
}