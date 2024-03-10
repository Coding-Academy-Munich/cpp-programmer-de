// Copyright (c) 2023 Dr. Matthias Hölzl. All rights reserved.

#include "Book.h"
#include "Utils.h"

#include <string_view>
#include <utility>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "UnusedValue"
namespace library::v2c {
using namespace std::literals::string_view_literals;

std::shared_ptr<BookInfo> BookInfo::Create(const std::string& isbn,
    const std::string& title, const std::vector<std::string>& authors,
    const std::string& publisher, std::chrono::year publicationYear,
    unsigned int edition)
{
    struct MakeSharedEnabler : public BookInfo {
        MakeSharedEnabler(std::string title, const std::vector<std::string>& authors,
            std::string isbn, std::string publisher, std::chrono::year publicationYear,
            unsigned int edition)
            : BookInfo(std::move(isbn), std::move(title), authors, std::move(publisher),
                publicationYear, edition)
        {
        }
    };

    return std::make_shared<MakeSharedEnabler>(
        title, authors, isbn, publisher, publicationYear, edition);
}

bool BookInfo::operator==(const BookInfo& rhs) const
{
    return isbn == rhs.GetIsbn() && title == rhs.GetTitle()
        && authors == rhs.GetAuthors() && publisher == rhs.GetPublisher()
        && edition == rhs.GetEdition() && publicationYear == rhs.GetPublicationYear();
}

BookInfo::BookInfo(std::string isbn, std::string title,
    const std::vector<std::string>& authors, std::string publisher,
    const std::chrono::year& publicationYear, unsigned int edition)
    : isbn {std::move(isbn)}
    , title {std::move(title)}
    , authors {authors}
    , publisher {std::move(publisher)}
    , publicationYear {publicationYear}
    , edition {edition}
{
}

std::ostream& operator<<(std::ostream& os, const BookInfo& info)
{
    os << "BookInfo{isbn: " << info.GetIsbn() << ", title: " << info.GetTitle()
       << ", authors: " << JoinVector {info.GetAuthors()}
       << ", publisher: " << info.GetPublisher()
       << ", year: " << info.GetPublicationYear() << ", edition: " << info.GetEdition()
       << "}";
    return os;
}

unsigned int Book::nextId {1};

bool Book::HasAuthor(const std::string& basicString) const
{
    return info->HasAuthor(basicString);
}

std::ostream& operator<<(std::ostream& os, const Book& book)
{
    os << "Book{id: " << book.GetId() << ", isbn: " << book.GetIsbn()
       << ", title: " << book.GetTitle()
       << ", authors: " << JoinVector {book.GetAuthors()}
       << ", publisher: " << book.GetPublisher()
       << ", year: " << book.GetPublicationYear() << ", edition: " << book.GetEdition()
       << "}";
    return os;
}

} // namespace library::v2c
#pragma clang diagnostic pop