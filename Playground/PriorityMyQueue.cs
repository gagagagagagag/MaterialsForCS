
using System.Collections.Generic;

namespace Playground
{
    public class MyPriorityQueue<T> : GenericQueue<T>
    {
        public override void Enqueue(T item)
        {
            if (list.Count == 0)
            {
                list.AddFirst(item);
                return;
            }

            foreach (var element in list)
            {
                if (Comparer<T>.Default.Compare(item, element) < 0)
                {
                    list.AddBefore(list.Find(element), item);
                    return;
                }
            }

            list.AddLast(item);
        }
    }
}