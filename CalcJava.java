public class CalcJava {

    private static final long NANO_CONV_MS = 1_000_000; 

    public static void main(String[] args) {
        int n = 1000;

        if (args.length > 0) {
            n = Integer.parseInt(args[0]);
        }

        long[] A = new long[n * n];
        long[] B = new long[n * n];
        long[] C = new long[n * n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                A[i*n + j] = i + j;
                B[i*n + j] = i - j;
            }
        }

        final long start = System.nanoTime();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    C[i*n + j] += A[i*n + k] * B[k*n + j];
                }
            }
        }

        final long end = System.nanoTime();
        final long durationMs = (end - start) / NANO_CONV_MS;

        System.out.println(durationMs + "ms");
        System.out.println(C[0]);
    }

}