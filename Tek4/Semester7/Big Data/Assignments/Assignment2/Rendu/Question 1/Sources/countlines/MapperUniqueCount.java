package countlines;

import java.io.IOException;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapred.MapReduceBase;
import org.apache.hadoop.mapred.Mapper;
import org.apache.hadoop.mapred.OutputCollector;
import org.apache.hadoop.mapred.Reporter;

public class MapperUniqueCount extends MapReduceBase implements Mapper<Text, IntWritable, Text, IntWritable> {
	private final static IntWritable one = new IntWritable(1);
	private Text word = new Text("Unique terms in corpus : ");

	public void map(Text inputKey, IntWritable inputValue, OutputCollector<Text, IntWritable> output, Reporter reporter) throws IOException {
		output.collect(word, one);
	}
}
