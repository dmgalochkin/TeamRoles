#include "FrontendDeveloper.h"
#include <gtest.h>

TEST(FrontendDeveloperTest, CreateWithValidParameters) {
  std::string langs[] = {"JavaScript", "TypeScript"};
  std::string frameworks[] = {"React"};

  ASSERT_NO_THROW(
    FrontendDeveloper dev(
    25, 120000, "Anna", 4, 2,
    2, langs, "VSCode",
    1, frameworks, true
    )
  );
}

TEST(FrontendDeveloperTest, ThrowOnNegativeUIFrameworks) {
  std::string langs[] = {"HTML"};
  std::string frameworks[] = {"Vue"};

  ASSERT_ANY_THROW(
    FrontendDeveloper dev(
    22, 90000, "Kate", 3, 1,
    1, langs, "Sublime",
    -1, frameworks, false
    )
  );
}

TEST(FrontendDeveloperTest, DefaultValuesCorrect) {
  FrontendDeveloper dev;

  EXPECT_EQ(dev.GetAge(), 25);
  EXPECT_EQ(dev.GetSalary(), 50000);
  EXPECT_EQ(dev.GetNumberOfUIFrameworks(), 0);
  EXPECT_FALSE(dev.GetPWAKnowledge());
}

TEST(FrontendDeveloperTest, GetRoleReturnsCorrectValue) {
  FrontendDeveloper dev;
  EXPECT_EQ(dev.GetRole(), "FrontendDeveloper");
}

TEST(FrontendDeveloperTest, SetUIFrameworksWorks) {
  FrontendDeveloper dev;
  std::string frameworks[] = {"Angular", "Svelte"};

  ASSERT_NO_THROW(dev.SetUIFrameworks(2, frameworks));
  EXPECT_EQ(dev.GetNumberOfUIFrameworks(), 2);

  std::string* result = dev.GetUIFrameworks();
  EXPECT_EQ(result[0], "Angular");
  EXPECT_EQ(result[1], "Svelte");
  delete[] result;
}

TEST(FrontendDeveloperTest, SetPWAKnowledgeUpdatesValue) {
  FrontendDeveloper dev;

  dev.SetPWAKnowledge(true);
  EXPECT_TRUE(dev.GetPWAKnowledge());

  dev.SetPWAKnowledge(false);
  EXPECT_FALSE(dev.GetPWAKnowledge());
}

TEST(FrontendDeveloperTest, CopyConstructorDeepCopies) {
  std::string langs[] = {"TypeScript"};
  std::string frameworks[] = {"Next.js"};

  FrontendDeveloper orig(
    30, 150000, "Mike", 5, 3,
    1, langs, "WebStorm",
    1, frameworks, true
  );

  FrontendDeveloper copy(orig);

  // Проверка базовых полей
  EXPECT_EQ(copy.GetName(), "Mike");
  EXPECT_EQ(copy.GetPWAKnowledge(), true);

  // Проверка копирования массивов
  std::string* origFrameworks = orig.GetUIFrameworks();
  std::string* copyFrameworks = copy.GetUIFrameworks();
  EXPECT_NE(origFrameworks, copyFrameworks); // Указатели должны быть разные
  EXPECT_EQ(copyFrameworks[0], "Next.js");

  delete[] origFrameworks;
  delete[] copyFrameworks;
}

TEST(FrontendDeveloperTest, ThrowOnInvalidLevel) {
  std::string langs[] = {"CSS"};
  std::string frameworks[] = {"Bootstrap"};

  ASSERT_ANY_THROW( // Уровень 0
    FrontendDeveloper dev(
    20, 30000, "Lena", 3, 0,
    1, langs, "Atom",
    1, frameworks, false
    )
  );

  ASSERT_ANY_THROW( // Уровень 4
    FrontendDeveloper dev(
    20, 30000, "Lena", 3, 4,
    1, langs, "Atom",
    1, frameworks, false
    )
  );
}

TEST(FrontendDeveloperTest, ThrowOnLowSalary) {
  std::string langs[] = {"PHP"};
  std::string frameworks[] = {"Laravel"};

  ASSERT_ANY_THROW(
    FrontendDeveloper dev(
    30, 29999, "Ivan", 5, 2,
    1, langs, "PHPStorm",
    1, frameworks, true
    )
  );
}