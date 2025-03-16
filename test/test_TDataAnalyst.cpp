#include "TDataAnalyst.h"
#include <gtest.h>

TEST(DataAnalystTest, CreateWithValidParameters) {
  std::string tools[] = {"Python", "SQL"};

  ASSERT_NO_THROW(
          TDataAnalyst da(
    28, 85000, "Anna", 3,
    "Jupyter", 2, tools,
    "Apache Hadoop", "Tableau"
    )
  );
}

TEST(DataAnalystTest, DefaultConstructorValues) {
  TDataAnalyst da;
  EXPECT_EQ(da.GetAge(), 25);
  EXPECT_EQ(da.GetSalary(), 50000);
  EXPECT_EQ(da.GetBigDataPlatform(), "Google BigQuery");
  EXPECT_EQ(da.GetDataVisualizationTool(), "Datawrapper");
}

TEST(DataAnalystTest, ThrowOnEmptyPlatformInConstructor) {
  std::string tools[] = {"Excel"};
  ASSERT_ANY_THROW(
          TDataAnalyst da(
  25, 50000, "John", 2,
  "CSV", 1, tools,
  "", "PowerBI"
    )
  );
}

TEST(DataAnalystTest, GetRoleReturnsCorrectValue) {
  TDataAnalyst da;
  EXPECT_EQ(da.GetRole(), "DataAnalyst");
}

TEST(DataAnalystTest, SetMethodsValidation) {
  TDataAnalyst da;

  ASSERT_ANY_THROW(da.SetBigDataPlatform(""));
  ASSERT_ANY_THROW(da.SetDataVisualizationTool(""));

  ASSERT_NO_THROW(da.SetBigDataPlatform("AWS"));
  ASSERT_NO_THROW(da.SetDataVisualizationTool("Looker"));

  EXPECT_EQ(da.GetBigDataPlatform(), "AWS");
  EXPECT_EQ(da.GetDataVisualizationTool(), "Looker");
}

TEST(DataAnalystTest, CopyConstructorValues) {
  std::string tools[] = {"R", "Spark"};

  TDataAnalyst original(
    35, 120000, "Maria", 5,
    "PDF", 2, tools,
    "Databricks", "Redash"
  );

  TDataAnalyst copy(original);

  EXPECT_EQ(copy.GetName(), "Maria");
  EXPECT_EQ(copy.GetBigDataPlatform(), "Databricks");
  EXPECT_EQ(copy.GetDataVisualizationTool(), "Redash");
}

TEST(DataAnalystTest, MinimumSalaryValidation) {
  std::string tools[] = {"PowerBI"};

  ASSERT_ANY_THROW(
          TDataAnalyst da(
      22, 19999, "Kate", 1,
      "PPT", 1, tools,
      "Snowflake", "Qlik"
    )
  );
}

TEST(DataAnalystTest, WorkExperienceValidation) {
  std::string tools[] = {"Tableau"};

  ASSERT_ANY_THROW(
          TDataAnalyst da(
    24, 25000, "Alex", 0,
    "Word", 1, tools,
    "Google Cloud", "Metabase"
    )
  );
}