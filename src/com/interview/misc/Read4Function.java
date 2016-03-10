package com.interview.misc;

import java.util.Arrays;

/**
 * Given a reader which only reads 4 bytes implement a Reader which can read bytes of give size.
 */
public class Read4Function {

    private final Reader reader;
    private final Queue queue;
    public Read4Function() {
        this.reader = new Reader();
        queue = new Queue(4);
    }

    public byte[] read(int size) {
        byte[] output = new byte[size];
        int n = 0;
        while (!queue.isEmpty() && n < size) {
            output[n++] = queue.poll();
        }

        if (n == size) {
            return output;
        }

        int remaining = size - n;
        byte[] b = null;
        while (remaining > 0) {
            b = reader.read();
            copy(b, output, 0, n, remaining > 4 ? 4 : remaining);
            n += 4;
            remaining -= 4;
        }
        for (int i = 4 + remaining; i < 4; i++) {
            queue.offer(b[i]);
        }

        return output;
    }

    private void copy(byte[] src, byte[] destination, int sourceStart, int destinationStart, int size) {
        int i = sourceStart;
        int j = destinationStart;
        while (i < sourceStart + size) {
            destination[j++] = src[i++];
        }
    }

    public static void main(String args[]) {
        Read4Function rf = new Read4Function();
        System.out.println(Arrays.toString(rf.read(2)));
        System.out.println(Arrays.toString(rf.read(1)));
        System.out.println(Arrays.toString(rf.read(1)));
        System.out.println(Arrays.toString(rf.read(5)));
        System.out.println(Arrays.toString(rf.read(2)));
        System.out.println(Arrays.toString(rf.read(8)));
        System.out.println(Arrays.toString(rf.read(7)));
        System.out.println(Arrays.toString(rf.read(17)));
        System.out.println(Arrays.toString(rf.read(1)));
    }
}

class Queue {
    int start;
    int end;
    int count;
    byte[] data;
    int size;
    Queue(int size) {
        data = new byte[size];
        this.size = size;
    }

    boolean isEmpty() {
        return count == 0;
    }

    void offer(byte b) {
        data[start] = b;
        start = (start + 1)%size;
        count++;
    }

    byte poll() {
        byte d = data[end];
        end = (end + 1)%size;
        count--;
        return d;
    }
}

class Reader {
    int index = 0;
    byte[] read() {
        byte[] b = new byte[4];
        for (int i = index; i < index + 4; i++) {
            b[i - index] = (byte)i;
        }
        index += 4;
        return b;
    }
}
