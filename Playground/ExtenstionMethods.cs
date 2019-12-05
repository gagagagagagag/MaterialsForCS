using System.Numerics;
using System.Text;

namespace Playground
{
    public static class ExtensionMethods
    {
        //here implement CheckDivision and TransformString
        public static bool CheckDivision(this int integer, int divisor)
        {
            return integer % divisor == 0;
        }

        public static string TransformString(this string inputString)
        {
            string outputString = "";
            for (int i = 0; i < inputString.Length; i++)
            {
                if (i % 2 == 0)
                {
                    outputString += inputString[i].ToString().ToUpper();
                }
                else
                {
                    outputString += inputString[i];
                }

                outputString += " ";
            }

            return outputString;
        }
    }
}