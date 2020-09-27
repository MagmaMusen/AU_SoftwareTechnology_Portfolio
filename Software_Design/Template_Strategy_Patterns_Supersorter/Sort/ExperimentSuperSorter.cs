using System.Diagnostics;
using System;

namespace supersorter.Sort
{
    public class ExperimentSuperSorter : SuperSorter
    {
        private Stopwatch _stopWatch;

        public ExperimentSuperSorter(int[] unsorted): base(unsorted) {
            _stopWatch = new Stopwatch();
        }

        protected override void Start() {
            _stopWatch.Reset();
            _stopWatch.Start();
        }

        protected override long Stop() {
            _stopWatch.Stop();
            return _stopWatch.ElapsedMilliseconds;

        }

    }
}