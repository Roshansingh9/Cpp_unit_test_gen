Here is the test code for the `PersonsController` class:

```cpp
#include "gtest/gtest.h"
#include "../utils/utils.h"
#include <memory>
#include <vector>
#include <regex>

using namespace drogon::orm;
using namespace drogon_model::org_chart;

TEST(PersonsControllerTest, TestGet) {
    // Create a mock HttpRequest and HttpResponse for testing.
    auto req = std::make_shared<drogon::HttpRequest>();
    auto resp = std::make_shared<drogon::HttpResponse>();

    // Set the request parameters
    req->setOptionalParameter("sort_field", "id");
    req->setOptionalParameter("sort_order", "asc");
    req->setOptionalParameter("limit", "25");
    req->setOptionalParameter("offset", "0");

    // Test the get function.
    PersonsController controller;
    controller.get(req, [&resp](const drogon::HttpResponsePtr &response) {
        resp = response;
    });

    // Check if the response is correct.
    EXPECT_EQ(resp->getStatusCode(), 200);
    auto jsonResp = resp->getBody().toString();
    Json::Value jsonData;
    jsonResp.parse(jsonData);
    EXPECT_TRUE(!jsonData.empty());
}

TEST(PersonsControllerTest, TestGetOne) {
    // Create a mock HttpRequest and HttpResponse for testing.
    auto req = std::make_shared<drogon::HttpRequest>();
    auto resp = std::make_shared<drogon::HttpResponse>();

    // Set the request parameters
    req->setOptionalParameter("sort_field", "id");
    req->setOptionalParameter("sort_order", "asc");
    req->setOptionalParameter("limit", "25");
    req->setOptionalParameter("offset", "0");

    int personId = 1;
    PersonsController controller;
    controller.getOne(req, [&resp](const drogon::HttpResponsePtr &response) {
        resp = response;
    }, personId);

    // Check if the response is correct.
    EXPECT_EQ(resp->getStatusCode(), 200);
    auto jsonResp = resp->getBody().toString();
    Json::Value jsonData;
    jsonResp.parse(jsonData);
    EXPECT_TRUE(!jsonData.empty());
}

TEST(PersonsControllerTest, TestCreateOne) {
    // Create a mock HttpRequest and HttpResponse for testing.
    auto req = std::make_shared<drogon::HttpRequest>();
    auto resp = std::make_shared<drogon::HttpResponse>();

    // Set the request parameters
    Persons person;
    person.setId(1);
    person.setFirstName("John");
    person.setLastName("Doe");

    int personId = 1;
    PersonsController controller;
    controller.createOne(req, [&resp](const drogon::HttpResponsePtr &response) {
        resp = response;
    }, person);

    // Check if the response is correct.
    EXPECT_EQ(resp->getStatusCode(), 201);
    auto jsonResp = resp->getBody().toString();
    Json::Value jsonData;
    jsonResp.parse(jsonData);
    EXPECT_TRUE(!jsonData.empty());
}

TEST(PersonsControllerTest, TestUpdateOne) {
    // Create a mock HttpRequest and HttpResponse for testing.
    auto req = std::make_shared<drogon::HttpRequest>();
    auto resp = std::make_shared<drogon::HttpResponse>();

    int personId = 1;
    Persons person;
    person.setId(1);
    person.setFirstName("John");
    person.setLastName("Doe");

    PersonsController controller;
    controller.updateOne(req, [&resp](const drogon::HttpResponsePtr &response) {
        resp = response;
    }, personId, person);

    // Check if the response is correct.
    EXPECT_EQ(resp->getStatusCode(), 204);
}

TEST(PersonsControllerTest, TestDeleteOne) {
    // Create a mock HttpRequest and HttpResponse for testing.
    auto req = std::make_shared<drogon::HttpRequest>();
    auto resp = std::make_shared<drogon::HttpResponse>();

    int personId = 1;
    PersonsController controller;
    controller.deleteOne(req, [&resp](const drogon::HttpResponsePtr &response) {
        resp = response;
    }, personId);

    // Check if the response is correct.
    EXPECT_EQ(resp->getStatusCode(), 204);
}

TEST(PersonsControllerTest, TestGetDirectReports) {
    // Create a mock HttpRequest and HttpResponse for testing.
    auto req = std::make_shared<drogon::HttpRequest>();
    auto resp = std::make_shared<drogon::HttpResponse>();

    int personId = 1;
    PersonsController controller;
    controller.getDirectReports(req, [&resp](const drogon::HttpResponsePtr &response) {
        resp = response;
    }, personId);

    // Check if the response is correct.
    EXPECT_EQ(resp->getStatusCode(), 200);
    auto jsonResp = resp->getBody().toString();
    Json::Value jsonData;
    jsonResp.parse(jsonData);
    EXPECT_TRUE(!jsonData.empty());
}
```

These tests cover all public functions in the `PersonsController` class. They use mocks for the HttpRequest and HttpResponse to test the different methods of the controller.