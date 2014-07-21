package com.interview.multithreaded;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.Callable;
import java.util.concurrent.CompletionService;
import java.util.concurrent.ExecutorCompletionService;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Future;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;

public class ThreadPoolExample {

	private static BlockingQueue<Runnable> queue = new ArrayBlockingQueue<Runnable>(10);
	public static ExecutorService threadPool =  new ThreadPoolExecutor(2, 10, 1000, TimeUnit.SECONDS,queue, new ThreadPoolExecutor.CallerRunsPolicy());
	
	public void doWork() throws Exception{
		CompletionService<String> completionService = new ExecutorCompletionService<String>(threadPool);
		
		Count10 count1 = new Count10(1);
		Count10 count2 = new Count10(2);
		Count10 count3 = new Count10(3);
		
		List<Future<String>> futureList = new ArrayList<Future<String>>();
		futureList.add(completionService.submit(count1));
		futureList.add(completionService.submit(count2));
		futureList.add(completionService.submit(count3));
		
		for(int i=0; i < 3; i++){
			Future<String> future = completionService.take();
			System.out.println(future.get());
		}
	}
	
	public static void main(String args[]) throws Exception{
		ThreadPoolExample tpe = new ThreadPoolExample();
		tpe.doWork();
	}
	
}

class Count10 implements Callable<String>{

	private int index = 0;
	Count10(int i){
		index = i;
	}
	@Override
	public String call() throws Exception {
		for(int i=0; i < 10; i++){
			System.out.println("Print i for " + index + ":" + i);
			int sleepTime = (int)(Math.random()*1000) + 1;
			try {
				Thread.sleep(sleepTime);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		return "Done" + index;
	}
	
}
