package pg1;

public class Main {
    public static void main(String[] args) throws Exception {
        MyKNNodel model = new MyKNNodel("34",
                "-K 3 -W 0 -A \"weka.core.2neighboursearch.LinearNNSearch -A \\\"weka.core.EuclideanDistance -R first-last\\\"\"",
                null);
        model.buildKNN("D:\\Ky_2_Nam4\\train_labor1.arff");
        model.evaluateKNN("D:\\Ky_2_Nam4\\labor_test.arff");
        model.predictClassLabel("D:\\Ky_2_Nam4\\unlabel.arff", "D:\\Ky_2_Nam4\\Multimedia_data_mining\\divide_data\\src\\out\\test_knn.arff");
        System.out.println(model);
    }
}