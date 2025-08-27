
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
            scene.WriteCache("", @"E:\Temp\nwc\test.nwc");
            Console.WriteLine("\nEnd!");
        }
    }
}
