namespace Playground
{
    public class Book
    {
        public string Name { get; set; }
        public int Year { get; set; }

        public override string ToString()
        {
            return Name + ", " + Year;
        }
    }
}