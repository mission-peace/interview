package com.interview.multithreaded;

import java.util.LinkedList;
import java.util.Queue;

public class ConsumerProducerProblem {

	public static void main(String args[]) {
		Broker broker = new Broker();
		Consumer consumer = new Consumer(broker);
		Producer producer = new Producer(broker);
		Thread tConsumer = new Thread(consumer);
		Thread tProducer = new Thread(producer);
		tConsumer.start();
		tProducer.start();
	}
}

class Consumer implements Runnable {

	private Broker broker = null;

	Consumer(Broker broker) {
		this.broker = broker;
	}

	@Override
	public void run() {
		try {
			while (true) {
				synchronized (broker) {
					broker.wait(1000);
					System.out.println("Data consumed " + broker.fetchData());
				}
			}
		} catch (InterruptedException e) {
		}
	}

}

class Producer implements Runnable {

	private Broker broker = null;

	Producer(Broker broker) {
		this.broker = broker;
	}

	@Override
	public void run() {
		int i = 0;
		while (i < 20) {
			synchronized (broker) {
				System.out.println("Adding data to broker ");
				broker.addMessage(i);
				broker.notifyAll();
			}
			try {
				int sleepTime = ((int) ((Math.random()) * 100) + 1);
				Thread.sleep(sleepTime);
			} catch (InterruptedException e) {
			}
		i++;

		}
	}

}

class Broker {

	private Queue<Integer> queue = new LinkedList<Integer>();

	public synchronized void addMessage(int data) {
		queue.offer(data);
	}

	public synchronized int fetchData() {
		if (queue.size() == 0) {
			return -1;
		}
		return queue.poll();
	}

}
