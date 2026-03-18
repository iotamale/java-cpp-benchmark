public class CalcJava {

    public static void main(String[] args) {
        int n = 1000;

        if (args.length > 0) {
            n = Integer.parseInt(args[0]);
        }

        long[][] A = new long[n][n];
        long[][] B = new long[n][n];
        long[][] C = new long[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                A[i][j] = i+j;
                B[i][j] = i-j;
            }
        }

        final long start = System.nanoTime();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        final long end = System.nanoTime();
        final long durationMs = (end-start) / 1000000;

        System.out.println(durationMs + "ms");
        System.out.println(C[0][0]);
    }

}