package pg1;

import weka.classifiers.lazy.IBk;
import weka.classifiers.Evaluation;
import weka.core.Instances;
import weka.core.converters.ConverterUtils.DataSource;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.util.Random;

public class MyKNNodel extends MyKnowledgeModel {
    IBk knn;
    Evaluation eval;

    public MyKNNodel(String filename, String m_opts, String d_opts) throws Exception {
        super(filename, m_opts, d_opts);
    }

    // build knn model
    public void buildKNN(String fileName) throws Exception {
        // doc train set vao bo nho
        setTrainSet(fileName);
        // thiet lap va chi ro trường đóng vai trò nhan lop
        this.trainSet.setClassIndex(this.trainSet.numAttributes() - 1);
        // train model KNN
        this.knn = new IBk(); // khoi tao mo hinh
        knn.setOptions(model_options); // khoi tao mo hinh, dua option cua mo hinh vao
        knn.buildClassifier(this.trainSet); // tien hanh xay dung mo hinh
    }

    public void evaluateKNN(String fileName) throws Exception {
        setTestSet(fileName); // doc test set vao bo nho
        this.testSet.setClassIndex(this.testSet.numAttributes()-1);

        // danh gia mo hinh bang 10-fold cross validation
        Random rd = new Random(1);
        int folds = 10;
        eval = new Evaluation(this.trainSet);
        eval.crossValidateModel(knn, this.testSet, folds, rd);
        System.out.println(eval.toSummaryString("\nKet qua danh gia mo hinh kNN---\n", false));
    }

    public void predictClassLabel(String fileIn, String fileOut) throws Exception {
        // Doc du lieu can du doan vao bo nho: file unlabel
        DataSource source = new DataSource(fileIn);
        Instances unLabel = source.getDataSet();
        unLabel.setClassIndex(unLabel.numAttributes() - 1);

        // du doan classLabel cho tung instances
        for (int i = 0; i < unLabel.numInstances() ; i++) {
            double predict = knn.classifyInstance(unLabel.instance(i));
            unLabel.instance(i).setClassValue(predict);
        }

        // xuat ket qua ra fileOut
        BufferedWriter outBuff = new BufferedWriter(new FileWriter(fileOut));
        outBuff.write(unLabel.toString());
        outBuff.newLine();
        outBuff.flush();
        outBuff.close();
    }
}
