#include <cstdint>
#include <ostream>
#include <stdexcept>
#include <string>
#include <vector>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace ::testing;

enum class Side
{
    Buy,
    Sell
};

std::ostream& operator<<(std::ostream& out, Side side)
{
    switch (side)
    {
        case Side::Buy:
            return out << "Buy";
        case Side::Sell:
            return out << "Sell";
    }
    return out << "Unknown side";
}

struct OrderInfo
{
    static constexpr int InvalidOrderId = -1;

    std::string order_id;
    double price;
    std::uint64_t volume;
    Side side;
};

// We can create simple matchers by composing existing matchers and returning them.
Matcher<std::string> IsValidOrderId()
{
    return Not(IsEmpty());
}

std::ostream& operator<<(std::ostream& out, const OrderInfo& order)
{
    out << "OrderInfo[OrderId=" << order.order_id;
    out << ", Price=" << order.price;
    out << ", Volume=" << order.volume;
    out << ", Side=" << order.side << "]";
    return out;
}

struct Orders
{
    std::string book;
    std::vector<OrderInfo> orders;
};

class OrderTest : public Test
{
protected:
    Orders getEvent(int eventId) const
    {
        // Obviously this is canned data, but let's not get distracted with fancy simulations...
        switch (eventId)
        {
            case 1:
                return {
                    "RDSA",
                    {
                        OrderInfo{.order_id = "event1-1", .price = 1.23, .volume = 100, .side = Side::Buy},
                        OrderInfo{.order_id = "event1-3", .price = 1.25, .volume = 300, .side = Side::Buy},
                        OrderInfo{.order_id = "event1-2", .price = 1.24, .volume = 200, .side = Side::Buy},
                    }};

            case 2:
                return {"RDSA", {}};
        }
        throw std::runtime_error("Event not received");
    }
};

TEST_F(OrderTest, Event1OrdersAreSentOnTheCorrectBook)
{
    // TODO: Use StrEq to ensure the book is "RDSA" in the following EXPECT_THAT assertion.

    // EXPECT_THAT(getEvent(1).book, /* Fill me in */);
    FAIL() << "This test needs to be implemented.";
}

TEST_F(OrderTest, Event1OrderIdsAreAllValid)
{
    // EXAMPLE: GoogleTest has some great matchers for working with collections. E.g. we can ensure that each OrderInfo
    // has a valid order id using `Each`.

    EXPECT_THAT(getEvent(1).orders, Each(Field("order_id", &OrderInfo::order_id, IsValidOrderId())));
}

TEST_F(OrderTest, Event1ExpectedPrices)
{
    // The collection based GoogleTest matchers are better than testing individual elements in a for loop as they
    // express the intent of the testing better and produce better error messages that provide context. E.g. Using
    // UnorderedElementsAre vs ElementsAre informs the developer as to whether the order matters or not.

    // TODO: use EXPECT_THAT with the Field, UnorderedElementsAre, and appropriate floating point matchers to ensure
    // that the prices are 1.23, 1.24, 1.25.

    FAIL() << "This test needs to be implemented.";
}

TEST_F(OrderTest, Event1AllOrdersAreBuySide)
{
    // TODO: You should be able to work this one out from the test name.

    FAIL() << "This test needs to be implemented.";
}

TEST_F(OrderTest, Event1OrderIdsStartWithEventDash1)
{
    // TODO: Ensure that all order ids for event 1 start with the text "event1-"
    // EXPECT_THAT(getEvent().orders, /* Fill me in */);

    FAIL() << "This test needs to be implemented.";
}

TEST_F(OrderTest, Event1ExpectedOrders)
{
    // TODO: Write a *single* EXPECT_THAT statement that verifies the following orders. Note: You will need to use the
    // AllOf matcher alongside UnorderedElementsAre. Note: the test should ensure that the price 1.23 is in the order
    // with volume 100, i.e. separate tests for price and volume are not sufficient. The expected orders are:
    //   Price | Volume
    //   1.23  | 100
    //   1.24  | 200
    //   1.25  | 300

    FAIL() << "This test needs to be implemented.";

    // TODO: Extension exercise:
    // The above can be verbose. Can you write a simple matcher to remove the duplication? (Hint: IsValidOrderId shows
    // *one* way of creating a custom matcher. There are other ways in the GoogleTest documentation.)
    // Create a simple matcher and duplicate the above EXPECT_THAT statement you wrote above with your new matcher.

    FAIL()
        << "The extension exercise needs to be implemented. Remove this if you are not going to complete the extension";
}

TEST_F(OrderTest, Event2OrdersAreEmpty)
{
    // TODO: Use the *most* appropriate matcher to ensure the collection is empty.

    FAIL() << "This test needs to be implemented.";
}

TEST_F(OrderTest, UnknownEventIdThrows)
{
    // TODO: Find an appropriate assertion to ensure an exception of type std::runtime_error is thrown when an event
    // does not exist. Use `getEvent(999)`.

    FAIL() << "This test needs to be implemented.";
}

TEST_F(OrderTest, GettingKnownEventDoesNotThrow)
{
    // TODO: Find an appropriate assertion to ensure that no exception is thrown when retrieving a known event.

    FAIL() << "This test needs to be implemented.";
}

