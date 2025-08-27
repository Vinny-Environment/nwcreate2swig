
namespace nwcreateNET_Test
{
    internal class Program
    {
        static void Main(string[] args)
        {
            LcNwcSceneWrapper scene = new LcNwcSceneWrapper();
            LcNwcGroupWrapper group = new LcNwcGroupWrapper();
            group.SetLayer(true);
            group.SetName("test");
            scene.AddNode(group);
            scene.WriteCache("", @"C:\Users\Georg\Documents\GitHub\VinnyLibBin\Debug\dependencies\nwcreate\test.nwc");
            Console.WriteLine("\nEnd!");
        }
    }
}
