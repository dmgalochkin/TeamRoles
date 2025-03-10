#include "ProductAnalyst.h"
#include <gtest.h>

TEST(ProductAnalystTest, CreateWithValidParameters) {
std::string tools[] = {"Google Analytics"};
std::string metrics[] = {"Conversion Rate"};

  ASSERT_NO_THROW(
          ProductAnalyst pa(
          30, 60000, "Anna", 3,
          "PDF", 1, tools,
          1, metrics, "Optimizely"
  )
  );
}

TEST(ProductAnalystTest, DefaultConstructorValues) {
  ProductAnalyst pa;

  EXPECT_EQ(pa.GetAge(), 25);
  EXPECT_EQ(pa.GetSalary(), 50000);
  EXPECT_EQ(pa.GetNumberOfProductMetrics(), 0);
  EXPECT_EQ(pa.GetAbTestingTool(), "Adobe Target");
}

TEST(ProductAnalystTest, ThrowOnNegativeProductMetrics) {
  std::string tools[] = {"Mixpanel"};
  std::string metrics[] = {"DAU"};

  ASSERT_ANY_THROW(
    ProductAnalyst pa(
    28, 50000, "John", 2,
    "CSV", 1, tools,
    -1, metrics, "VWO"
  )
  );
}

TEST(ProductAnalystTest, GetRoleReturnsCorrectValue) {
  ProductAnalyst pa;
  EXPECT_EQ(pa.GetRole(), "ProductAnalyst");
}

TEST(ProductAnalystTest, SetProductMetricsWorks) {
  ProductAnalyst pa;
  std::string metrics[] = {"Retention", "ARPU"};

  ASSERT_NO_THROW(pa.SetProductMetrics(2, metrics));
  EXPECT_EQ(pa.GetNumberOfProductMetrics(), 2);

  std::string* result = pa.GetProductMetrics();
  EXPECT_EQ(result[0], "Retention");
  EXPECT_EQ(result[1], "ARPU");
  delete[] result;
}

TEST(ProductAnalystTest, SetAbTestingToolValidation) {
  ProductAnalyst pa;

  ASSERT_ANY_THROW(pa.SetAbTestingTool(""));
  ASSERT_NO_THROW(pa.SetAbTestingTool("Google Optimize"));
  EXPECT_EQ(pa.GetAbTestingTool(), "Google Optimize");
}

TEST(ProductAnalystTest, CopyConstructorDeepCopy) {
  std::string tools[] = {"Amplitude"};
  std::string metrics[] = {"MAU"};

  ProductAnalyst original(
          35, 80000, "Maria", 5,
          "Excel", 1, tools,
          1, metrics, "AB Tasty"
  );

  ProductAnalyst copy(original);

  // Проверка базовых полей
  EXPECT_EQ(copy.GetName(), "Maria");
  EXPECT_EQ(copy.GetAbTestingTool(), "AB Tasty");

  // Проверка глубокого копирования метрик
  std::string* origMetrics = original.GetProductMetrics();
  std::string* copyMetrics = copy.GetProductMetrics();
  EXPECT_NE(origMetrics, copyMetrics);
  EXPECT_EQ(copyMetrics[0], "MAU");

  delete[] origMetrics;
  delete[] copyMetrics;
}

TEST(ProductAnalystTest, MinimumSalaryValidation) {
  std::string tools[] = {"Tableau"};
  std::string metrics[] = {"LTV"};

  ASSERT_ANY_THROW(
          ProductAnalyst pa(
  25, 19999, "Kate", 1,
  "PPT", 1, tools,
  1, metrics, "Unbounce"
  )
  );
}

TEST(ProductAnalystTest, WorkExperienceValidation) {
  std::string tools[] = {"PowerBI"};
  std::string metrics[] = {"NPS"};

  ASSERT_ANY_THROW(
          ProductAnalyst pa(
  22, 25000, "Alex", 0,
  "Word", 1, tools,
  1, metrics, "Convert"
  )
  );
}

TEST(ProductAnalystTest, EmptyAbTestingToolInConstructor) {
  std::string tools[] = {"Looker"};
  std::string metrics[] = {"CAC"};

  ASSERT_ANY_THROW(
          ProductAnalyst pa(
  27, 45000, "Peter", 2,
  "HTML", 1, tools,
  1, metrics, ""
  )
  );
}
