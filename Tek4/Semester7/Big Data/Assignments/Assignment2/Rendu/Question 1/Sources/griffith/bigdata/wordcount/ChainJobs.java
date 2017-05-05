package griffith.bigdata.wordcount;



import org.apache.hadoop.fs.FileSystem;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.conf.*;
import org.apache.hadoop.io.*;
import org.apache.hadoop.mapred.*;
import org.apache.hadoop.util.*;

public class ChainJobs extends Configured implements Tool {

	@Override
	public int run(String[] args) throws Exception {
		// JOB 1
		JobConf job1 = new JobConf(ChainJobs.class);
		job1.setJobName("unique");

		job1.setOutputKeyClass(Text.class);
		job1.setOutputValueClass(IntWritable.class);

		job1.setMapperClass(unique.MyMapper.class);
		job1.setReducerClass(unique.MyReducer.class);

		job1.setInputFormat(TextInputFormat.class);
		job1.setOutputFormat(SequenceFileOutputFormat.class);

		FileInputFormat.setInputPaths(job1, new Path(args[0]), new Path(args[1]), new Path(args[2]));
		SequenceFileOutputFormat.setOutputPath(job1, new Path(args[3] + "-tmp"));

		JobClient.runJob(job1);
		
		job1.setMapperClass(countlines.MapperUniqueCount.class);
		job1.setReducerClass(countlines.MapperUniqueReducer.class);

		job1.setInputFormat(SequenceFileInputFormat.class);
		job1.setOutputFormat(TextOutputFormat.class);
		
		SequenceFileInputFormat.setInputPaths(job1, new Path(args[3] + "-tmp"));
		FileOutputFormat.setOutputPath(job1, new Path(args[3]));
		
		JobClient.runJob(job1);
		
		return 0;
	}
	public static void main(String[] args) throws Exception {
		if (args.length != 4) {
			System.err.println("Enter valid number of arguments <Inputdirectory>  <Outputlocation>");
			System.exit(0);
		}
		FileSystem fs = FileSystem.get(new Configuration());
		fs.delete(new Path(args[3]), true);
		fs.delete(new Path(args[3] + "-tmp"), true);
		ToolRunner.run(new Configuration(), new ChainJobs(), args);
	}
}
