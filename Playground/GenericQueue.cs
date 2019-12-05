using System;
using System.Collections.Generic;

namespace Playground
{
    public abstract class GenericQueue<T> : IQueue<T>
    {
        protected LinkedList<T> list = new LinkedList<T>();

        public virtual void Enqueue(T item)
        {
            
        }

        public T Dequeue()
        {
            if (list.Count == 0)
            {
                throw new Exception("Queue is empty");
            } 
            
            T element = list.First.Value;
            list.RemoveFirst();
            return element;
        }

        public T Peek()
        {
            if (list.Count == 0)
            {
                throw new Exception("Queue is empty");
            } 
            
            return list.First.Value;
        }

        public int Count
        {
            get
            {
                return list.Count;
            }
        }

        public override string ToString()
        {
            string outputString = "";
            foreach (var item in list)
            {
                outputString += item + " ";
            }

            return outputString;
        }
    }
}