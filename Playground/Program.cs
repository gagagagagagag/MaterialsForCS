using System;
using System.Linq;

namespace ENG_Lab05
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            Console.WriteLine();
            Console.WriteLine(" >>> Part 1 -- List shapes <<<");
            Console.WriteLine();

            // @TODO. Part 1 -- List shapes [2pt]
            // Create the Shape classes hierarchy to make the initialiation and the listing work.
            // Leave the Point class not derivated from anything.
            // All shape classes are derivated from Shape.
            //   Rectangle constructor takes coordinates of the left upper and right bottom corners (X1, Y1, X2, Y2).
            //   Circle constructor takes coordinates of a center and a radius.
            //   Line constructor takes coordinates of two points which it is drawn through (X1, Y1, X2, Y2).
            // Make sure to redefine the ToString method appropriatery, to fit the resulting output.
            //
            // Note!
            // 1. For the matter of this laboratory task, assume that we work in the standard Euclidean coordinate system.
            // X coordinate grows from left to right, Y coordinate grows from bottom to up.
            // 2. In this task it is forbidden to use default constructors (without parameters).
            // 3. Rectangle here is basic versions of these shapes, aligned to the axes (X and Y), this case does not cover rotation.

            Shape[] shapes =
            {
                new Rectangle(1, 4, 6, 1),
                new Circle(5, 4, 2),
                new Rectangle(2, 8, 5, 1),
                new Line(2, 1, 8, 4),
                new Rectangle(7, 5, 12, 3),
                new Circle(4, 0, 3),
            };
            for (int i = 0; i < shapes.Length; i++)
                Console.WriteLine(shapes[i]);

            Console.WriteLine();
            Console.WriteLine(" >>> Part 2 -- Use shapes <<<");
            Console.WriteLine();

            for (int i = 0; i < shapes.Length; i++)
            {
                shapes[i].PrintInfo();
                
                // @TODO. Part 2 -- Use shapes [1pt]
                // Print shape measurements, including specific information:
                //   a. An area of every Shape. For this matter define the abstract method Area in the Shape class.
                //   b. A length of Rectangle diagonals.
                //   c. A circumference of Circles.
                //
                // Note!
                // The number formatting may be used in the string interpolation, i.e. $"{variableName:0.##}".
                
                
            }

            Console.WriteLine();
            Console.WriteLine(" >>> Part 3 -- \"Produce\" shapes <<<");
            Console.WriteLine();

            // @TODO: Part 3 -- "Produce" shapes [1pt]
            // Create the factory method PickUp with two overloads which constructs shapes with default values:
            //   Line - in case of "l"
            //   Circle - in case of "c"
            //   Rectangle - in case of "r"
            // Use the switch construction for this task.
            // Default values:
            //   Line: (0,0), (1,1)
            //   Rectangle: (1,3), (7,1)
            //   Circle: (3,5), r = 3

            Shape[] shapes2 = { Shape.PickUp("r"), Shape.PickUp("c"), Shape.PickUp("l") };
            Shape[] shapes3 = Shape.PickUp("r", "c", "l");

            Console.WriteLine("Shapes 2:");
            for (int i = 0; i < shapes2.Length; i++)
                Console.WriteLine(shapes2[i]);

            Console.WriteLine("Shapes 3:");
            for (int i = 0; i < shapes3.Length; i++)
                Console.WriteLine(shapes3[i]);

            Console.WriteLine();
            Console.WriteLine(" >>> Part 4 -- Deconstruct shapes <<<");
            Console.WriteLine();

            // @TODO Part 4 -- Move shapes [1pt]
            // Implement a method which will move a shape into a specified point, aligning the shape center at that point.

            Point anchor1 = new Point(0, 8);
            Point anchor2 = new Point(15, 7);
            Shape.MoveShape(shapes2, anchor1);
            Shape.MoveShape(shapes3, anchor2);

            Console.WriteLine("Shapes 2:");
            for (int i = 0; i < shapes2.Length; i++)
                Console.WriteLine(shapes2[i]);

            Console.WriteLine("Shapes 3:");
            for (int i = 0; i < shapes3.Length; i++)
                Console.WriteLine(shapes3[i]);

            Console.WriteLine();
            Console.WriteLine(" >>> Part 5 -- Cover points <<<");
            Console.WriteLine();

            // @TODO. Part 5 -- Cover centers [1pt]
            // Find the smallest frame (two Point objects is enough) to cover centers of all created shapes (shapes, shapes2, shapes3).

            /*
             * Replace this comment block with your code.
             */

            double minY = 1000, maxY = 0, minX = 1000, maxX = 0;
            int m;
            Shape[] tablicaShapeow=new Shape[shapes.Length+shapes2.Length+shapes3.Length];
            for ( m = 0; m < shapes.Length; m++)
            {
                tablicaShapeow[m] = shapes[m];
            }

            int k;

            for ( k = 0; k < shapes2.Length; k++)
            {
                tablicaShapeow[m + k] = shapes2[k];
            }

            int j;

            for (j = 0; j < shapes3.Length; j++)
            {
                tablicaShapeow[m + j + k] = shapes3[j];
            }

            foreach (var shape in tablicaShapeow)
            {
                Point shapeCenter = shape.getCenter();

                if (shapeCenter.X > maxX)
                {
                    maxX = shapeCenter.X;
                }
                if (shapeCenter.X < minX)
                {
                    minX = shapeCenter.X;
                }
                if (shapeCenter.Y > maxY)
                {
                    maxY = shapeCenter.Y;
                }
                if (shapeCenter.Y < minY)
                {
                    minY = shapeCenter.Y;
                }
            }
            System.Console.WriteLine($"Points are ({minX},{minY}) and ({maxX},{maxY})");
            

        }
    }
}