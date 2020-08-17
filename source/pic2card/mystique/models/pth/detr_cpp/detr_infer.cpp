#include <iostream>
#include <string>
#include <tuple>

#include <opencv2/opencv.hpp>
#include <torch/extension.h>
#include <torch/script.h>
#include <torch/torch.h>


// using namespace std;
// using namespace cv;

// Scale sizes
int main(int argc, const char *argv[])
{
    std::string model_path = "/mnt1/haridas/projects/pic2card-models/pytorch/detr_trace.pt";
    std::string image_path = "/mnt1/haridas/projects/mystique/data/templates_test_data/1.png";

    // if (argc != 3)
    // {
    //   std::cerr << "usage: detr-app <path-to-exported-script-module> <image-path> \n";
    //   return -1;
    // }
    try
    {
        // Deserialize image_pathiptModule from a file using torch::jit::load().
        cv::Mat image = cv::imread(image_path, 1);
        cv::cvtColor(image, image, cv::COLOR_BGR2RGB);
        //cv::Size scale(500, 600);
        //cv::resize(image, image, scale);
        cv::Size imsize = image.size();
        image.convertTo(image, CV_32FC3, 1.0f / 255.0f);
        //std::cout << "Image: " << image.size();

        //auto input_tensor = torch::from_blob(image.data, {1, 500, 600, 3});
        torch::Tensor input_tensor = torch::from_blob(image.data, { 1, imsize.width, imsize.height, 3 });
        input_tensor = input_tensor.permute({ 0, 3, 1, 2 });
        //std::cout << "Tensor: " << input_tensor[0][0].sizes();
        // Apply normalization based on imagenet data.
        input_tensor[0][0] = input_tensor[0][0].sub_(0.485).div_(0.229);
        input_tensor[0][1] = input_tensor[0][1].sub_(0.456).div_(0.224);
        input_tensor[0][2] = input_tensor[0][2].sub_(0.406).div_(0.225);

        torch::jit::script::Module module;
        module = torch::jit::load(model_path);
        // Create a vector of inputs.
        std::vector<torch::jit::IValue> inputs;
        //inputs.push_back(torch::ones({1, 3, 500, 600}));
        inputs.push_back(input_tensor);

        // Execute the model and turn its output into a tensor.
        auto outDict = module.forward(inputs).toGenericDict();
        // auto outDict = output.toGenericDict();

        //std::cout << "PredLogits: " << outDict.at("pred_logits") << " pred Boxes: " << outDict.at("pred_boxes") << std::endl;
        torch::Tensor predLogits = outDict.at("pred_logits")
            .toTensor()
            .squeeze()
            .softmax(-1);
        predLogits = predLogits.narrow(1, 0, predLogits.size(1) - 1);

        torch::Tensor predBoxes = outDict.at("pred_boxes").toTensor().squeeze();

        auto keep = predLogits.max(-1);
        auto keep1 = std::get<0>(keep); // apply threshold mask.
        torch::Tensor mask = keep1.ge_(0.8);

        mask = mask.to(torch::kBool);
        std::cout << mask << std::endl;
        //predBoxes = predBoxes.masked_select(mask);
        predLogits = predLogits.index_select(0, mask);
        // auto keep = predBoxes.max(-1) > 0.8;
        //std::vector<torch::Tensor> test = predLogits.toTensor();
    std::cout << predLogits;
    }
    catch (const c10::Error &e)
    {
        std::cerr << "error loading the model\n";
        std::cout << e.what() << "\n";
        return -1;
    }

    std::cout << "ok\n";
}