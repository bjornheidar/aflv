// Author: Kristinn Þröstur Sigurðarson

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * Created by Notandi on 07/12/2014.
 */
public class WateringGrass
{
	static class Interval implements Comparable<Interval> {
		double start;
		double end;

		public Interval(double s, double e) {
			start = s;
			end = e;

		}

		public int compareTo(Interval o) {
			if (Double.compare(start, o.start) != 0)
				return Double.compare(start, o.start);
			else
				return Double.compare(end, o.end);

		}
	}

	public static void main(String[] args)
	{
		boolean exit = true;
		Kattio io = new Kattio(System.in, System.out);
		while (exit)
		{

			int n = io.getInt();
			int l = io.getInt();
			int w = io.getInt();
			int sum= 0;
			Interval[] list = new Interval[n];
			for(int i = 0;i < n; i++)
			{
				double x = io.getInt();
				double r = io.getInt();
				double cubeLength = r * 0.707;
				double start = x - Math.sqrt((double)r * r - (w * w) / 4.0);
				double middle = x;
				double end = x + Math.sqrt((double)r * r - (w * w) / 4.0);
				list[i] = new Interval(start,end);


			}

			Arrays.sort(list);
			double end = 0;
			double begin = 0;
			int count = 0;
			int out = 0;
			int cnt = 0;
			boolean check = true;
			int i;
			while(end < l && check)
			{
				double max = end;
				check = false;
				for(i = count;i<n && list[i].start <= end;i++)
				{
					if(list[i].start <= end)
					{
						check = true;
						max = Math.max(max,list[i].end);
					}
				}
				if(end < max)
				{
					cnt++;
				}
				end = max;
				count = i;

			}

			if(end >= l)
			{
				io.println(cnt);
				io.flush();

			}
			else if(!check)
			{
				io.println(-1);
				io.flush();
			}
			end = 0;
			count = 0;
			cnt = 0;


			if(!io.hasMoreTokens())
			{
				io.close();
				exit = false;
			}

		}
		System.exit(0);





	}

}
