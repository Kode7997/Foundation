//Book=>categories=>

interface NoteBook {
    Integer countPages(Book b); // by default all are abstract, unless specified "default or static"
    //Integer countNumberOfVolumes(Book b);
}

class BookCategories{
    
    String categ;
    String dept;
    Integer cId;
    
    BookCategories(String categ, String dept, Integer cId){
        this.categ = categ;
        this.dept = dept;
        this.cId = cId;
    }

}

class Book extends BookCategories implements NoteBook {

    String name;
    Integer id;
    
    //constructor
    Book(String name, Integer id, String categ, String dept, Integer cId){
        super(categ, dept, cId);
        this.name = name;
        this.id = id;
        //add volume or edition
    }

    public String getBookName(Book b){
        return b.name;
    }

    public void setBookName(String name){
        this.name = name;
    }

    @Override
    public Integer countPages(Book b){
        return 200;
    }

    // @Override
    // Integer countNumberOfVolumes(Book b){
    //     return 1;
    // }
}

class Books{
    public static void main(String[] args) {
        Book book = new Book("sherlock",1,"fiction","novels",1);
        String name = book.getBookName(book);
        System.out.println("name of book: "+name);
        System.out.println("number of pages: "+book.countPages(book));
    }
}

