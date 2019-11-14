using System;
namespace ENG_Lab05
{
    public abstract class Shape
    {
        public abstract double Area();
        public abstract void PrintInfo();
        public abstract void MoveThisShape(Point x);
        public abstract Point getCenter();
        public Shape()
        {
            
        }

        public static void MoveShape(Shape []a, Point b)
        {
            foreach (Shape x in a)
            {
                x.MoveThisShape(b);
            }
            
        } 

        public static Shape PickUp(string x)
        {
            switch (x)
            {
               case "l":
                   return new Line(0, 0, 1, 1);
               case "c":
                   return new Circle(3,5,3);
               case "r":
                   return new Rectangle(1,3,7,1);
            }

            return null;
        }

        public static Shape[] PickUp(params string[] x)
        {
            Shape[] lista= new Shape[x.Length];
            for (int i = 0; i < x.Length; i++)
            {
                
                
                switch (x[i])
                {
                    case "l":
                        lista[i]= new Line(0, 0, 1, 1);
                        break;
                    case "c":
                        lista[i] = new Circle(3,5,3);
                        break;
                    case "r":
                        lista[i] = new Rectangle(1,3,7,1);
                        break;
                }
            }

            return lista;
        }
        
    }

    public class Point
    {
        public double X;
        public double Y;

        public Point(double a, double b)
        {
            this.X = a;
            this.Y = Y;
        }
    }

    public class Rectangle : Shape
    {
        public Point LeftUpper=new Point(0,0);
        public Point RightBottom=new Point(0,0);

        public override double Area()
        {
            double lena = this.LeftUpper.Y - this.RightBottom.Y;
            double lenb = this.RightBottom.X - this.LeftUpper.X;
            double A=lena * lenb;
            return A;

        }

        public override void MoveThisShape(Point x)
        {
            double lena = Math.Abs(this.LeftUpper.Y - this.RightBottom.Y);
            double lenb = Math.Abs(this.RightBottom.X - this.LeftUpper.X);

            this.LeftUpper.Y = x.Y+(lena*0.5);
            this.LeftUpper.X=x.X-(lenb/2);
            this.RightBottom.Y=x.Y-(lena*0.5);
            this.RightBottom.X=x.X+(lenb/2);           
        }

        public override Point getCenter()
        {
            double length = Math.Abs(this.LeftUpper.X - this.RightBottom.X);
            double height = Math.Abs(this.LeftUpper.Y - this.RightBottom.Y);
            
            return new Point(this.LeftUpper.X + length/2, this.LeftUpper.Y + length/2);
        }

        public double Diagonal()
        {
            return Math.Sqrt(this.LeftUpper.Y - this.RightBottom.Y * this.RightBottom.X - this.LeftUpper.X);
        }

        public override void PrintInfo()
        {
            Console.WriteLine($"{ToString()} area is {this.Area()}");
            Console.WriteLine($"{ToString()} diagonal is equal to : {this.Diagonal()}");
        }


        public override string ToString()
        {
            return $"This is rectangle from({this.LeftUpper.X},{this.LeftUpper.Y}) to ({this.RightBottom.X},{this.RightBottom.Y})";
        }

        public Rectangle(int x1, int y1, int x2, int y2)
        {
            this.LeftUpper.X = x1;
            this.LeftUpper.Y = y1;
            this.RightBottom.X = x2;
            this.RightBottom.Y = y2;
        }
    }

    public class Circle : Shape
    {
        public Point Center=new Point(0,0);
        public int Radius;
        public override string ToString()
        {
            return $"This is cycle with center at({this.Center.X},{this.Center.Y}) and radious equal to {this.Radius} ";
        }

        public override void MoveThisShape(Point x)
        {
            this.Center.X = x.X;
            this.Center.Y = x.Y;
        }

        double Circumference()
        {
            return 2 * 3.14 * this.Radius;
        }

        public override void PrintInfo()
        {
            Console.WriteLine($"{ToString()} area is {this.Area()}");
            Console.WriteLine($"{ToString()} Circumference is equal to : {this.Circumference()}");
        }


        public override double Area()
        {
            return 3.14 * this.Radius * this.Radius;
        }
        
        public override Point getCenter()
        {
            return new Point(this.Center.X, this.Center.Y);
        }


        public Circle(int x, int y, int c)
        {
            this.Radius = c;
            this.Center.X = x;
            this.Center.Y = y;
            
        }
    }

    public class Line : Shape
    {
        public Point A=new Point(0,0);
        public Point B=new Point(0,0);

        public Line(int x1,int y1,int x2, int y2)
        {
            this.A.X = x1;
            this.A.Y = y1;
            this.B.X = x2;
            this.B.Y = y1;
        }

        public override void MoveThisShape(Point x)
        {
            
            this.A.X = x.X - Math.Abs(this.A.X - this.B.X) * 0.5;
            this.B.X = x.X + Math.Abs(this.A.X - this.B.X) * 0.5;
            this.A.Y = x.Y - Math.Abs(this.A.Y - this.B.Y) * 0.5;
            this.B.X = x.Y + Math.Abs(this.A.Y - this.B.Y) * 0.5;
        }

        double Lengh()
        {
            return Math.Sqrt((this.B.X - this.A.X) * (this.B.Y - this.A.Y));
        }
        
        public override void PrintInfo()
        {
            Console.WriteLine($"{ToString()} area is {this.Area()}");
            Console.WriteLine($"{ToString()} lengh is equal to : {this.Lengh()}");
        }
        
        public override Point getCenter()
        {
            double length = Math.Abs(this.A.X - this.B.X);
            double height = Math.Abs(this.A.Y - this.B.Y);
            
            return new Point(this.A.X + length/2, this.A.Y + length/2);
        }

        public override double Area()
        {
            return 0.0;
        }
        
        public override string ToString()
        {
            return $"This is line from({this.A.X},{this.A.Y}) to ({this.B.X},{this.B.Y})";
        }
    }
}