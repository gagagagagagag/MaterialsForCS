using System.Collections.Generic;
using System.Runtime.CompilerServices;

namespace Playground
{
    public class MyQueue<T> : GenericQueue<T>
    {
        public override void Enqueue(T item)
        {
            list.AddLast(item);
        }
    }
}