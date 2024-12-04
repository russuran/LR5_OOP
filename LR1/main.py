class Book():
    def __init__(self, author: str, name: str, type: str = None) -> None:
        self.name = name
        self.type = type
        self.author = author
        
    def __repr__(self) -> str:
        return f'Книга {self.name}, автор: {self.author}, тип: {self.type}'
    

class Library():
    def __init__(self, list_of_books: list = None) -> None:
        self.list_of_books = list_of_books
    
    def get_amount_of_books_by_types(self, type_of_book) -> int:
        match type_of_book:
            case 'х':
                return sum(1 for book in self.list_of_books if book.type == 'х')
            case 'т':
                return sum(1 for book in self.list_of_books if book.type == 'т')
            case _:
                return 0  # Если тип не распознан, возвращаем 0
    
    def get_amount_of_books_by_types_easier(self, type_of_book) -> int:
        return sum(1 for book in self.list_of_books if book.type == type_of_book)
books = [
    Book(author="Автор 1", name="Книга 1", type="х"),
    Book(author="Автор 2", name="Книга 2", type="т"),
    Book(author="Автор 3", name="Книга 3", type="х"),
    Book(author="Автор 4", name="Книга 4", type="д"),
    Book(author="Автор 5", name="Книга 5", type="т"),
    Book(author="Автор 6", name="Книга 6", type="х"),
] #х - худож. т - технич.
lib = Library(books)
print(lib.get_amount_of_books_by_types('х'))
print(lib.get_amount_of_books_by_types_easier('т'))
